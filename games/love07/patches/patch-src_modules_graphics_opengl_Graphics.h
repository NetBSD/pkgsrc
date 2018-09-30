$NetBSD: patch-src_modules_graphics_opengl_Graphics.h,v 1.1 2018/09/30 19:10:11 maya Exp $

Match SDL1 include paths

--- src/modules/graphics/opengl/Graphics.h.orig	2011-05-04 16:00:10.000000000 +0000
+++ src/modules/graphics/opengl/Graphics.h
@@ -26,9 +26,9 @@
 #include <cmath>
 
 // SDL
-#include <SDL.h>
+#include <SDL/SDL.h>
 #include "GLee.h"
-#include <SDL_opengl.h>
+#include <SDL/SDL_opengl.h>
 
 // LOVE
 #include <graphics/Graphics.h>
