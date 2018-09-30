$NetBSD: patch-src_love.cpp,v 1.1 2018/09/30 19:10:11 maya Exp $

Match SDL1 include paths

--- src/love.cpp.orig	2011-05-04 16:00:10.000000000 +0000
+++ src/love.cpp
@@ -38,7 +38,7 @@
 #ifdef LOVE_BUILD_EXE
 
 // SDL
-#include <SDL.h>
+#include <SDL/SDL.h>
 
 // Modules
 #include <audio/wrap_Audio.h>
