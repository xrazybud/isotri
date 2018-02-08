#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <math.h>

int wwidth = 1280;
int wheight = 720;

ALLEGRO_KEYBOARD_STATE KeyboardYo;

int main(){
   al_init();
   al_init_primitives_addon();
   al_install_keyboard();

   al_set_new_display_flags(ALLEGRO_RESIZABLE);
   al_create_display(wwidth, wheight);

   int centerx = wwidth/2;
   int centery = wheight/2;

   float offset = 0;
   float length = centerx - 50;
   int growth = 1;
   while ( !al_key_down(&KeyboardYo, ALLEGRO_KEY_ESCAPE) ) { // ALLEGRO_KEY_ESCAPE
      if (growth%2) {length += 0.5;} else {length -= 0.5;}
      if (length > (centerx - 50) || length < (centerx - 70) ) growth++;

      al_draw_triangle(centerx-((centerx/5)*2), centery+((centery/5)*2),
                       centerx+((centerx/5)*2), centery+((centery/5)*2),
                       centerx                , ((centerx/5)*2) * sin(60)+((centery/5)*2),
                       al_map_rgb(0,108,255), 5);

      al_draw_line(centerx, centery+(centery/5*2)+350, centerx, centery-(centerx/5*2)-350, al_map_rgb(255,108,0), 3);

      al_draw_line(centerx-(centerx/3*2), centery+(centery/3*2),
                   centerx+(centerx/3*2), centery+(centery/3*2),
                   al_map_rgb(255,108,0), 3);

      al_draw_circle(centerx, centery, 5, al_map_rgb(255,108,0), 3);
      int x, y;
      float angle = 0.0;
      while (angle < 2 * 3.14) {
         x = length * cos(angle+offset);
         y = length * sin(angle+offset);
         al_draw_circle(x + (wwidth/2), y + (wheight/2), 5, al_map_rgb(0,y,255), 3);
         angle += 0.1;
      }
      offset = offset-0.01;
      if (offset > 360) offset = 0;

      al_flip_display();
      al_clear_to_color( al_map_rgb(200,200,200)  );
      al_get_keyboard_state(&KeyboardYo);
   }

   return 0;
}

