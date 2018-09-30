$NetBSD: patch-src_modules_timer_sdl_Timer.h,v 1.1 2018/09/30 19:10:11 maya Exp $

Match SDL1 include paths

--- src/modules/timer/sdl/Timer.h.orig	2011-05-04 16:00:10.000000000 +0000
+++ src/modules/timer/sdl/Timer.h
@@ -22,7 +22,7 @@
 #define LOVE_TIMER_SDL_TIMER_H
 
 // SDL
-#include <SDL.h>
+#include <SDL/SDL.h>
 
 // LOVE
 #include <common/Module.h>
