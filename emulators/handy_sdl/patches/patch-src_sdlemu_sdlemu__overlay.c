$NetBSD: patch-src_sdlemu_sdlemu__overlay.c,v 1.1 2012/11/19 23:22:39 joerg Exp $

--- src/sdlemu/sdlemu_overlay.c.orig	2012-11-19 20:00:29.000000000 +0000
+++ src/sdlemu/sdlemu_overlay.c
@@ -41,7 +41,7 @@ void sdlemu_close_overlay(void)
 /* NOTE: These RGB conversion functions are not intended for speed,
          only as examples.
 */
-inline void RGBtoYUV(Uint8 *rgb, int *yuv)
+static inline void RGBtoYUV(Uint8 *rgb, int *yuv)
 {
 //#if 1 /* these are the two formulas that I found on the FourCC site... */
 //	yuv[0] = 0.299*rgb[0] + 0.587*rgb[1] + 0.114*rgb[2];
@@ -64,7 +64,7 @@ inline void RGBtoYUV(Uint8 *rgb, int *yu
 	*/
 }
 
-inline void ConvertRGBtoYV12(SDL_Surface *s, SDL_Overlay *o)
+static inline void ConvertRGBtoYV12(SDL_Surface *s, SDL_Overlay *o)
 {
 	int x,y;
 	int yuv[3];
@@ -104,7 +104,7 @@ inline void ConvertRGBtoYV12(SDL_Surface
 	SDL_UnlockSurface(s);
 }
 
-inline void ConvertRGBtoIYUV(SDL_Surface *s, SDL_Overlay *o)
+static inline void ConvertRGBtoIYUV(SDL_Surface *s, SDL_Overlay *o)
 {
 	int x,y;
 	int yuv[3];
@@ -144,7 +144,7 @@ inline void ConvertRGBtoIYUV(SDL_Surface
 	SDL_UnlockSurface(s);
 }
 
-inline void ConvertRGBtoUYVY(SDL_Surface *s, SDL_Overlay *o)
+static inline void ConvertRGBtoUYVY(SDL_Surface *s, SDL_Overlay *o)
 {
 	int x,y;
 	int yuv[3];
@@ -177,7 +177,7 @@ inline void ConvertRGBtoUYVY(SDL_Surface
 	SDL_UnlockSurface(s);
 }
 
-inline void ConvertRGBtoYVYU(SDL_Surface *s, SDL_Overlay *o)
+static inline void ConvertRGBtoYVYU(SDL_Surface *s, SDL_Overlay *o)
 {
 	int x,y;
 	int yuv[3];
@@ -213,7 +213,7 @@ inline void ConvertRGBtoYVYU(SDL_Surface
 	SDL_UnlockSurface(s);
 }
 
-inline void ConvertRGBtoYUY2(SDL_Surface *s, SDL_Overlay *o)
+static inline void ConvertRGBtoYUY2(SDL_Surface *s, SDL_Overlay *o)
 {
 	int x,y;
 	int yuv[3];
@@ -249,7 +249,7 @@ inline void ConvertRGBtoYUY2(SDL_Surface
 	SDL_UnlockSurface(s);
 }
 
-inline void Convert32bit(SDL_Surface *display)
+static inline void Convert32bit(SDL_Surface *display)
 {
 
 		SDL_Surface *newsurf;
@@ -312,7 +312,7 @@ inline void Convert32bit(SDL_Surface *di
 
 }
 
-inline void sdlemu_draw_overlay(SDL_Surface *s, int size, int width, int height)
+void sdlemu_draw_overlay(SDL_Surface *s, int size, int width, int height)
 {
         static SDL_Rect		  src;
         static SDL_Rect		  dest;
