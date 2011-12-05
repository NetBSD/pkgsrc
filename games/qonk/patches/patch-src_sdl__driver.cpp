$NetBSD: patch-src_sdl__driver.cpp,v 1.1 2011/12/05 22:45:19 joerg Exp $

--- src/sdl_driver.cpp.orig	2011-12-05 21:39:04.000000000 +0000
+++ src/sdl_driver.cpp
@@ -5,6 +5,7 @@
 #include <SDL/SDL.h>
 #include <SDL/SDL_ttf.h>
 #include <cstdio>
+#include <cstdlib>
 
 #include "sdl_driver.h"
 #include "canvas.h"
