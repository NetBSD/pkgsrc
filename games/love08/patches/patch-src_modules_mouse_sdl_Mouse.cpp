$NetBSD: patch-src_modules_mouse_sdl_Mouse.cpp,v 1.1 2018/09/30 19:12:48 maya Exp $

Match include path for SDL<2

--- src/modules/mouse/sdl/Mouse.cpp.orig	2012-04-06 18:15:02.000000000 +0000
+++ src/modules/mouse/sdl/Mouse.cpp
@@ -21,7 +21,7 @@
 #include "Mouse.h"
 
 // SDL
-#include <SDL.h>
+#include <SDL/SDL.h>
 
 namespace love
 {
