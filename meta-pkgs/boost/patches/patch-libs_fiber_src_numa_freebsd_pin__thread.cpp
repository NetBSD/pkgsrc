$NetBSD: patch-libs_fiber_src_numa_freebsd_pin__thread.cpp,v 1.1 2018/05/06 18:56:35 minskim Exp $

Use pthread_setaffinity_np() on FreeBSD.

https://github.com/boostorg/fiber/commit/225b0d75

--- libs/fiber/src/numa/freebsd/pin_thread.cpp.orig	2018-04-11 13:49:02.000000000 +0000
+++ libs/fiber/src/numa/freebsd/pin_thread.cpp
@@ -7,10 +7,8 @@
 #include "boost/fiber/numa/pin_thread.hpp"
 
 extern "C" {
-#include <errno.h>
-#include <sys/param.h>
-#include <sys/cpuset.h>
-#include <sys/thread.h>
+#include <pthread.h>
+#include <pthread_np.h>
 }
 
 #include <system_error>
@@ -25,18 +23,19 @@ namespace numa {
 
 BOOST_FIBERS_DECL
 void pin_thread( std::uint32_t cpuid) {
-    pin_thread( cpuid, ::thr_self() );
+    pin_thread( cpuid, ::pthread_self() );
 }
 
 BOOST_FIBERS_DECL
 void pin_thread( std::uint32_t cpuid, std::thread::native_handle_type h) {
-	cpuset_t mask;
-	CPU_ZERO( & mask);
-	CPU_SET( cpuid, & mask);
-    if ( BOOST_UNLIKELY( 0 != ::cpuset_setaffinity( CPU_LEVEL_WHICH, CPU_WHICH_TID, h, sizeof( mask), & mask) ) ) {
+    cpuset_t set;
+    CPU_ZERO( & set);
+    CPU_SET( cpuid, & set);
+    int err = 0;
+    if ( BOOST_UNLIKELY( 0 != ( err = ::pthread_setaffinity_np( h, sizeof( set), & set) ) ) ) {
         throw std::system_error(
-                std::error_code( errno, std::system_category() ),
-                "::cpuset_setaffinity() failed");
+                std::error_code( err, std::system_category() ),
+                "pthread_setaffinity_np() failed");
     }
 }
 
