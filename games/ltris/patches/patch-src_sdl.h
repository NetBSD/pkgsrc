$NetBSD: patch-src_sdl.h,v 1.1 2013/03/02 18:11:07 joerg Exp $

--- src/sdl.h.orig	2013-03-01 22:03:43.000000000 +0000
+++ src/sdl.h
@@ -41,8 +41,8 @@ typedef struct {
 SDL_Surface* load_surf(char *fname, int f);
 SDL_Surface* create_surf(int w, int h, int f);
 void free_surf( SDL_Surface **surf );
-inline void lock_surf(SDL_Surface *sur);
-inline void unlock_surf(SDL_Surface *sur);
+void lock_surf(SDL_Surface *sur);
+void unlock_surf(SDL_Surface *sur);
 void blit_surf(void);
 void alpha_blit_surf(int alpha);
 void fill_surf(int c);
@@ -86,8 +86,8 @@ Font* load_font(char *fname);
 Font* load_fixed_font(char *fname, int off, int len, int w);
 void free_font(Font **sfnt);
 int  write_text(Font *sfnt, SDL_Surface *dest, int x, int y, char *str, int alpha);
-inline void lock_font(Font *sfnt);
-inline void unlock_font(Font *sfnt);
+void lock_font(Font *sfnt);
+void unlock_font(Font *sfnt);
 SDL_Rect last_write_rect(Font *fnt);
 int  text_width(Font *fnt, char *str);
 
@@ -132,14 +132,14 @@ Video_Mode* cur_video_mode();
 char** get_mode_names( int *count );
 int  set_video_mode( Video_Mode mode );
 void hardware_cap();
-inline void refresh_screen( int x, int y, int w, int h );
+void refresh_screen( int x, int y, int w, int h );
 void refresh_rects();
 void add_refresh_rect(int x, int y, int w, int h);
 int  wait_for_key();
 void wait_for_click();
-inline void lock_screen();
-inline void unlock_screen();
-inline void flip_screen();
+void lock_screen();
+void unlock_screen();
+void flip_screen();
 void fade_screen( int type, int ms );
 void take_screenshot( int i );
 
@@ -148,8 +148,8 @@ void take_screenshot( int i );
 SDL_Cursor* create_cursor( int width, int height, int hot_x, int hot_y, char *source );
 
 /* timer */
-inline int get_time();
-inline void reset_timer();
+int get_time();
+void reset_timer();
 
 #ifdef __cplusplus
 };
