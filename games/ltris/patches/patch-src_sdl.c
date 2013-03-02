$NetBSD: patch-src_sdl.c,v 1.1 2013/03/02 18:11:07 joerg Exp $

--- src/sdl.c.orig	2013-03-01 22:03:50.000000000 +0000
+++ src/sdl.c
@@ -244,7 +244,7 @@ done:
 #endif
 
 /* return full path of bitmap */
-inline void get_full_bmp_path( char *full_path, char *file_name )
+void get_full_bmp_path( char *full_path, char *file_name )
 {
     sprintf(full_path,  "%s/gfx/%s", SRC_DIR, file_name );
 }
@@ -330,7 +330,7 @@ void free_surf( SDL_Surface **surf )
 /*
     lock surface
 */
-inline void lock_surf(SDL_Surface *sur)
+void lock_surf(SDL_Surface *sur)
 {
     if (SDL_MUSTLOCK(sur))
         SDL_LockSurface(sur);
@@ -339,7 +339,7 @@ inline void lock_surf(SDL_Surface *sur)
 /*
     unlock surface
 */
-inline void unlock_surf(SDL_Surface *sur)
+void unlock_surf(SDL_Surface *sur)
 {
     if (SDL_MUSTLOCK(sur))
         SDL_UnlockSurface(sur);
@@ -666,7 +666,7 @@ int write_text(Font *fnt, SDL_Surface *d
 /*
     lock font surface
 */
-inline void lock_font(Font *fnt)
+void lock_font(Font *fnt)
 {
     if (SDL_MUSTLOCK(fnt->pic))
         SDL_LockSurface(fnt->pic);
@@ -675,7 +675,7 @@ inline void lock_font(Font *fnt)
 /*
     unlock font surface
 */
-inline void unlock_font(Font *fnt)
+void unlock_font(Font *fnt)
 {
     if (SDL_MUSTLOCK(fnt->pic))
         SDL_UnlockSurface(fnt->pic);
@@ -905,7 +905,7 @@ void hardware_cap()
 /*
     update rectangle (0,0,0,0)->fullscreen
 */
-inline void refresh_screen(int x, int y, int w, int h)
+void refresh_screen(int x, int y, int w, int h)
 {
     SDL_UpdateRect(sdl.screen, x, y, w, h);
 }
@@ -1055,7 +1055,7 @@ void wait_for_click()
 /*
     lock surface
 */
-inline void lock_screen()
+void lock_screen()
 {
     if (SDL_MUSTLOCK(sdl.screen))
         SDL_LockSurface(sdl.screen);
@@ -1064,7 +1064,7 @@ inline void lock_screen()
 /*
     unlock surface
 */
-inline void unlock_screen()
+void unlock_screen()
 {
     if (SDL_MUSTLOCK(sdl.screen))
         SDL_UnlockSurface(sdl.screen);
@@ -1073,7 +1073,7 @@ inline void unlock_screen()
 /*
     flip hardware screens (double buffer)
 */
-inline void flip_screen()
+void flip_screen()
 {
     SDL_Flip(sdl.screen);
 }
@@ -1132,7 +1132,7 @@ SDL_Cursor* create_cursor( int width, in
 /*
     get milliseconds since last call
 */
-inline int get_time()
+int get_time()
 {
     int ms;
     cur_time = SDL_GetTicks();
@@ -1148,7 +1148,7 @@ inline int get_time()
 /*
     reset timer
 */
-inline void reset_timer()
+void reset_timer()
 {
     last_time = SDL_GetTicks();
 }
