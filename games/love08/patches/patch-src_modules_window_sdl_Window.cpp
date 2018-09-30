$NetBSD: patch-src_modules_window_sdl_Window.cpp,v 1.1 2018/09/30 19:12:48 maya Exp $

Match include path for SDL<2

--- src/modules/window/sdl/Window.cpp.orig	2012-04-06 18:15:02.000000000 +0000
+++ src/modules/window/sdl/Window.cpp
@@ -22,7 +22,7 @@
 #include <iostream>
 
 // SDL
-#include <SDL.h>
+#include <SDL/SDL.h>
 
 // OpenGL
 #include <SDL/SDL_opengl.h>
