$NetBSD: patch-source_source_ref__gl_qgl.h,v 1.1 2025/09/29 13:31:29 nia Exp $

- Add support for more Unix-like platforms.

--- source/source/ref_gl/qgl.h.orig	2016-03-26 19:22:10.000000000 +0000
+++ source/source/ref_gl/qgl.h
@@ -67,14 +67,14 @@ Foundation, Inc., 59 Temple Place - Suit
 #include <windows.h>
 #endif
 #include <GL/gl.h>
+#ifndef _WIN32
+#include <GL/glx.h>
+#endif
 #endif
 
 #if defined (__ANDROID__)
 #include <GLES2/gl2.h>
 #include <EGL/egl.h>
-
-#elif defined (__linux__) || defined (__FreeBSD__)
-#include <GL/glx.h>
 #endif
 
 #if defined (__MACOSX__)
