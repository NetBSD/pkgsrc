$NetBSD: patch-base_mutex.cc,v 1.6 2021/02/15 14:50:23 ryoon Exp $

* NetBSD support

--- base/mutex.cc.orig	2021-02-15 03:48:53.000000000 +0000
+++ base/mutex.cc
@@ -148,7 +148,7 @@ Mutex::Mutex() {
   // PTHREAD_MUTEX_RECURSIVE_NP but Mac OS X 10.5 does not
   pthread_mutexattr_t attr;
   pthread_mutexattr_init(&attr);
-#if defined(__APPLE__) || defined(OS_WASM)
+#if defined(__APPLE__) || defined(OS_WASM) || defined(OS_NETBSD)
   pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
 #elif defined(OS_LINUX) || defined(OS_ANDROID)
   pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE_NP);
