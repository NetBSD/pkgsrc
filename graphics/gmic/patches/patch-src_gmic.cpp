$NetBSD: patch-src_gmic.cpp,v 1.1 2020/05/23 10:44:02 ryoon Exp $

* Support NetBSD.

--- src/gmic.cpp.orig	2020-03-28 13:25:12.000000000 +0000
+++ src/gmic.cpp
@@ -2324,7 +2324,11 @@ bool *gmic::abort_ptr(bool *const p_is_a
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
@@ -2677,7 +2681,11 @@ gmic::~gmic() {
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
