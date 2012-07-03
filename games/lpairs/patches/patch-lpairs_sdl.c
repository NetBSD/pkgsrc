$NetBSD: patch-lpairs_sdl.c,v 1.1 2012/07/03 18:42:58 joerg Exp $

--- lpairs/sdl.c.orig	2012-07-03 16:02:59.000000000 +0000
+++ lpairs/sdl.c
@@ -480,7 +480,7 @@ void hardware_cap()
 /*
     update rectangle (0,0,0,0)->fullscreen
 */
-inline void refresh_screen(int x, int y, int w, int h)
+void refresh_screen(int x, int y, int w, int h)
 {
     SDL_UpdateRect(sdl.screen, x, y, w, h);
 }
