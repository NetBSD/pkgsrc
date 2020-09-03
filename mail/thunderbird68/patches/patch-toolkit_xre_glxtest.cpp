$NetBSD: patch-toolkit_xre_glxtest.cpp,v 1.1 2020/09/03 20:22:26 ryoon Exp $

--- toolkit/xre/glxtest.cpp.orig	2019-09-09 23:43:45.000000000 +0000
+++ toolkit/xre/glxtest.cpp
@@ -132,7 +132,7 @@ void glxtest() {
         "The MOZ_AVOID_OPENGL_ALTOGETHER environment variable is defined");
 
     ///// Open libGL and load needed symbols /////
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 #  define LIBGL_FILENAME "libGL.so"
 #else
 #  define LIBGL_FILENAME "libGL.so.1"
