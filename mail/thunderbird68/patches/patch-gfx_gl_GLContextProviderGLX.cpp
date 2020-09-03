$NetBSD: patch-gfx_gl_GLContextProviderGLX.cpp,v 1.1 2020/09/03 20:22:26 ryoon Exp $

Pick portable version of libGL.so.

--- gfx/gl/GLContextProviderGLX.cpp.orig	2019-09-09 23:43:27.000000000 +0000
+++ gfx/gl/GLContextProviderGLX.cpp
@@ -80,7 +80,7 @@ bool GLXLibrary::EnsureInitialized() {
     // which trigger glibc bug
     // http://sourceware.org/bugzilla/show_bug.cgi?id=12225
     const char* libGLfilename = "libGL.so.1";
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__)
     libGLfilename = "libGL.so";
 #endif
 
