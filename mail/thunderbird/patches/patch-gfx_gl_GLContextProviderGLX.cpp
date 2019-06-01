$NetBSD: patch-gfx_gl_GLContextProviderGLX.cpp,v 1.1 2019/06/01 23:27:58 kamil Exp $

Pick portable version of libGL.so.

--- gfx/gl/GLContextProviderGLX.cpp.orig	2019-05-17 12:04:28.000000000 +0000
+++ gfx/gl/GLContextProviderGLX.cpp
@@ -80,7 +80,7 @@ bool GLXLibrary::EnsureInitialized() {
     // implementation requires an executable stack, which causes mprotect calls,
     // which trigger glibc bug
     // http://sourceware.org/bugzilla/show_bug.cgi?id=12225
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__)
     libGLfilename = "libGL.so";
 #else
     libGLfilename = "libGL.so.1";
