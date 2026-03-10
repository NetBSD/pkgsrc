$NetBSD: patch-src_utils_src_utils_gl__include.h,v 1.1 2026/03/10 09:09:54 adam Exp $

Fix build on Darwin.

--- src/utils/src/utils/gl_include.h.orig	2026-03-10 08:40:27.314681845 +0000
+++ src/utils/src/utils/gl_include.h
@@ -11,11 +11,10 @@
 #ifndef __GL_INCLUDE_HEADER__
 #define __GL_INCLUDE_HEADER__
 
+#include <GL/glew.h>
 #ifdef __APPLE__
-#include <OpenGL/glew.h>
 #include <OpenGL/gl.h>
 #else
-#include <GL/glew.h>
 #include <GL/gl.h>
 #endif
 
