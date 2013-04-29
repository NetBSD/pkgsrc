$NetBSD: patch-base_mutex.cc,v 1.1 2013/04/29 09:52:17 ryoon Exp $

--- base/mutex.cc.orig	2013-03-29 04:33:43.000000000 +0000
+++ base/mutex.cc
@@ -61,7 +61,7 @@ namespace mozc {
 
 // Wrapper for Windows InterlockedCompareExchange
 namespace {
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
 // Linux doesn't provide InterlockedCompareExchange-like function.
 inline int InterlockedCompareExchange(volatile int *target,
                                       int new_value,
@@ -80,7 +80,7 @@ inline int InterlockedCompareExchange(vo
   pthread_mutex_unlock(&lock);
   return result;
 }
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_NETBSD
 
 // Use OSAtomicCompareAndSwapInt on Mac OSX
 // http://developer.apple.com/iphone/library/documentation/
@@ -91,7 +91,7 @@ inline int InterlockedCompareExchange(vo
                                       int new_value,
                                       int old_value) {
   return OSAtomicCompareAndSwapInt(old_value, new_value, target)
-      ? old_value : *target;
+      ? old_value : *target; || OS_NETBSD
 }
 #endif  // OX_MACOSX
 
@@ -296,7 +296,7 @@ Mutex::Mutex() {
   // PTHREAD_MUTEX_RECURSIVE_NP but Mac OS X 10.5 does not
   pthread_mutexattr_t attr;
   pthread_mutexattr_init(&attr);
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_NETBSD)
   pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
 #elif defined(OS_LINUX)
   pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE_NP);
