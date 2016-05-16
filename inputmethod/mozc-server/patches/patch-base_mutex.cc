$NetBSD: patch-base_mutex.cc,v 1.4 2016/05/16 11:51:49 ryoon Exp $

--- base/mutex.cc.orig	2016-05-15 08:11:10.000000000 +0000
+++ base/mutex.cc
@@ -53,7 +53,7 @@ namespace mozc {
 
 // Wrapper for Windows InterlockedCompareExchange
 namespace {
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL) || defined(OS_NETBSD)
 // Linux doesn't provide InterlockedCompareExchange-like function.
 inline int InterlockedCompareExchange(volatile int *target,
                                       int new_value,
@@ -72,7 +72,7 @@ inline int InterlockedCompareExchange(vo
   pthread_mutex_unlock(&lock);
   return result;
 }
-#endif  // OS_LINUX || OS_ANDROID || OS_NACL
+#endif  // OS_LINUX || OS_ANDROID || OS_NACL || OS_NETBSD
 
 // Use OSAtomicCompareAndSwapInt on Mac OSX
 // http://developer.apple.com/iphone/library/documentation/
@@ -85,7 +85,7 @@ inline int InterlockedCompareExchange(vo
   return OSAtomicCompareAndSwapInt(old_value, new_value, target)
       ? old_value : *target;
 }
-#endif  // OX_MACOSX
+#endif  // OS_MACOSX
 
 }  // namespace
 
@@ -183,7 +183,7 @@ Mutex::Mutex() {
   // PTHREAD_MUTEX_RECURSIVE_NP but Mac OS X 10.5 does not
   pthread_mutexattr_t attr;
   pthread_mutexattr_init(&attr);
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_NETBSD)
   pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
 #elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL)
   pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE_NP);
