$NetBSD: patch-src_unix_display__sdl.c,v 1.1 2018/04/09 15:03:22 ryoon Exp $

--- src/unix/display_sdl.c.orig	2003-12-20 09:47:50.000000000 +0000
+++ src/unix/display_sdl.c
@@ -34,7 +34,7 @@ static INLINE void debug(char *s) {
 	fprintf(stderr,"%s\n",s);
 }
 
-void sdl_InitialiseKeyboardMapping(void);
+void sdl_InitialiseKeyboardMapping(int);
 void sdl_InitialiseJoysticks(void);
 
 void sdl_SetDisplay(int Width, int Height, int Depth, BOOL fullscreen) {
