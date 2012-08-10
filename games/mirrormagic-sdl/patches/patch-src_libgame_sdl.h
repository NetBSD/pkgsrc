$NetBSD: patch-src_libgame_sdl.h,v 1.1 2012/08/10 18:04:53 joerg Exp $

--- src/libgame/sdl.h.orig	2012-08-10 12:21:02.000000000 +0000
+++ src/libgame/sdl.h
@@ -314,20 +314,20 @@ struct XY
 
 /* SDL function definitions */
 
-inline void SDLInitVideoDisplay(void);
-inline void SDLInitVideoBuffer(DrawBuffer **, DrawWindow **, boolean);
-inline boolean SDLSetVideoMode(DrawBuffer **, boolean);
-inline void SDLCopyArea(Bitmap *, Bitmap *, int, int, int, int, int, int, int);
-inline void SDLFillRectangle(Bitmap *, int, int, int, int, unsigned int);
-inline void SDLDrawSimpleLine(Bitmap *, int, int, int, int, unsigned int);
-inline void SDLDrawLine(Bitmap *, int, int, int, int, Uint32);
-inline Pixel SDLGetPixel(Bitmap *, int, int);
+void SDLInitVideoDisplay(void);
+void SDLInitVideoBuffer(DrawBuffer **, DrawWindow **, boolean);
+boolean SDLSetVideoMode(DrawBuffer **, boolean);
+void SDLCopyArea(Bitmap *, Bitmap *, int, int, int, int, int, int, int);
+void SDLFillRectangle(Bitmap *, int, int, int, int, unsigned int);
+void SDLDrawSimpleLine(Bitmap *, int, int, int, int, unsigned int);
+void SDLDrawLine(Bitmap *, int, int, int, int, Uint32);
+Pixel SDLGetPixel(Bitmap *, int, int);
 
 Bitmap *SDLLoadImage(char *);
 
-inline void SDLOpenAudio(void);
-inline void SDLCloseAudio(void);
+void SDLOpenAudio(void);
+void SDLCloseAudio(void);
 
-inline void SDLNextEvent(Event *);
+void SDLNextEvent(Event *);
 
 #endif /* SDL_H */
