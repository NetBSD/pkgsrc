$NetBSD: patch-base_mutex.cc,v 1.5 2017/12/17 14:15:43 tsutsui Exp $

* NetBSD support

--- base/mutex.cc.orig	2017-11-02 13:32:45.000000000 +0000
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
 // https://developer.apple.com/library/prerelease/mac/documentation/Darwin/Reference/ManPages/man3/OSAtomicCompareAndSwapInt.3.html
@@ -84,7 +84,7 @@ inline int InterlockedCompareExchange(vo
   return OSAtomicCompareAndSwapInt(old_value, new_value, target)
       ? old_value : *target;
 }
-#endif  // OX_MACOSX
+#endif  // OS_MACOSX
 
 }  // namespace
 
@@ -182,7 +182,7 @@ Mutex::Mutex() {
   // PTHREAD_MUTEX_RECURSIVE_NP but Mac OS X 10.5 does not
   pthread_mutexattr_t attr;
   pthread_mutexattr_init(&attr);
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_NETBSD)
   pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
 #elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL)
   pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE_NP);
