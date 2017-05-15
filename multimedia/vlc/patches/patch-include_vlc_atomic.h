$NetBSD: patch-include_vlc_atomic.h,v 1.2 2017/05/15 10:26:19 jperkin Exp $

clang ships everything we need, just use <atomic> instead of the
vlc_atomic.h #ifdef maze.

--- include/vlc_atomic.h.orig	2015-02-02 19:42:28.000000000 +0000
+++ include/vlc_atomic.h
@@ -32,7 +32,14 @@
 /*** Native C11 atomics ***/
 #  include <stdatomic.h>
 
+#elif defined(__cplusplus) && defined(__clang__)
+#include <atomic>
+using std::atomic_uint_least32_t;
+using std::atomic_uintptr_t;
+using std::atomic_uint;
 # else
+#include <sys/types.h>
+#include <stdint.h>
 
 #  define ATOMIC_FLAG_INIT false
 
