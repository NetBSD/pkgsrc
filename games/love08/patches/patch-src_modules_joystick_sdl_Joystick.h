$NetBSD: patch-src_modules_joystick_sdl_Joystick.h,v 1.1 2018/09/30 19:12:48 maya Exp $

Match include path for SDL<2

--- src/modules/joystick/sdl/Joystick.h.orig	2012-04-06 18:15:02.000000000 +0000
+++ src/modules/joystick/sdl/Joystick.h
@@ -26,7 +26,7 @@
 #include <common/EnumMap.h>
 
 // SDL
-#include <SDL.h>
+#include <SDL/SDL.h>
 
 namespace love
 {
