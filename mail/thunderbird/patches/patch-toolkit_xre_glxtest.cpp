$NetBSD: patch-toolkit_xre_glxtest.cpp,v 1.1 2018/12/16 08:12:16 ryoon Exp $

--- toolkit/xre/glxtest.cpp.orig	2018-12-04 23:12:02.000000000 +0000
+++ toolkit/xre/glxtest.cpp
@@ -124,7 +124,7 @@ void glxtest()
     fatal_error("The MOZ_AVOID_OPENGL_ALTOGETHER environment variable is defined");
 
   ///// Open libGL and load needed symbols /////
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__)
   #define LIBGL_FILENAME "libGL.so"
 #else
   #define LIBGL_FILENAME "libGL.so.1"
