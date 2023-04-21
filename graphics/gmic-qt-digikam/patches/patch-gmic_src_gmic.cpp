$NetBSD: patch-gmic_src_gmic.cpp,v 1.1 2023/04/21 09:09:31 wiz Exp $

* Support NetBSD.
https://github.com/GreycLab/gmic/pull/449

--- gmic/src/gmic.cpp.orig	2023-04-17 02:59:18.000000000 +0000
+++ gmic/src/gmic.cpp
@@ -2204,7 +2204,11 @@ inline void* get_tid() {
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
