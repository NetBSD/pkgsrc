$NetBSD: patch-src_love.cpp,v 1.1 2018/09/30 19:12:48 maya Exp $

Match include path for SDL<2

--- src/love.cpp.orig	2012-04-06 18:15:01.000000000 +0000
+++ src/love.cpp
@@ -37,7 +37,7 @@
 #ifdef LOVE_BUILD_EXE
 
 // SDL
-#include <SDL.h>
+#include <SDL/SDL.h>
 
 // Libraries.
 #include "libraries/luasocket/luasocket.h"
