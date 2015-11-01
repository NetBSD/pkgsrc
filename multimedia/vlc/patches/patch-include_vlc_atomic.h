$NetBSD: patch-include_vlc_atomic.h,v 1.1 2015/11/01 20:15:06 tnn Exp $

clang ships everything we need, just use <atomic> instead of the
vlc_atomic.h #ifdef maze.

--- include/vlc_atomic.h.orig	2014-08-14 07:20:03.000000000 +0000
+++ include/vlc_atomic.h
@@ -32,6 +32,11 @@
 /*** Native C11 atomics ***/
 #  include <stdatomic.h>
 
+#elif defined(__cplusplus) && defined(__clang__)
+#include <atomic>
+using std::atomic_uint_least32_t;
+using std::atomic_uintptr_t;
+using std::atomic_uint;
 # else
 
 #  define ATOMIC_FLAG_INIT false
