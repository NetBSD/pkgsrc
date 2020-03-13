$NetBSD: patch-gfx_gl_GLContextProviderGLX.cpp,v 1.4 2020/03/13 17:59:27 wiz Exp $

NetBSD doesn't ship libGL.so.1 due to a major bump. Look for the unversioned
name.
https://hg.mozilla.org/integration/mozilla-inbound/rev/8bcc51aaa91e

--- gfx/gl/GLContextProviderGLX.cpp.orig	2019-05-17 00:33:26.000000000 +0000
+++ gfx/gl/GLContextProviderGLX.cpp
@@ -80,7 +80,7 @@ bool GLXLibrary::EnsureInitialized() {
     // which trigger glibc bug
     // http://sourceware.org/bugzilla/show_bug.cgi?id=12225
     const char* libGLfilename = "libGL.so.1";
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__)
     libGLfilename = "libGL.so";
 #endif
 
