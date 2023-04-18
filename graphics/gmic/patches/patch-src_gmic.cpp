$NetBSD: patch-src_gmic.cpp,v 1.3 2023/04/18 16:04:02 wiz Exp $

* Support NetBSD.
https://github.com/GreycLab/gmic/pull/449

--- src/gmic.cpp.orig	2023-04-04 16:20:28.000000000 +0000
+++ src/gmic.cpp
@@ -2205,7 +2205,11 @@ inline void* get_tid() {
 #if defined(__MACOSX__) || defined(__APPLE__)
   void* tid = (void*)(cimg_ulong)getpid();
 #elif cimg_OS==1
+#if defined(__NetBSD__)
+  void* tid = (void*)(cimg_ulong)pthread_self();
+#else
   void* tid = (void*)(cimg_ulong)syscall(SYS_gettid);
+#endif
 #elif cimg_OS==2
   void* tid = (void*)(cimg_ulong)GetCurrentThreadId();
 #else
