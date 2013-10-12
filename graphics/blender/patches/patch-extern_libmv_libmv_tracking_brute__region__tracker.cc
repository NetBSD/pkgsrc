$NetBSD: patch-extern_libmv_libmv_tracking_brute__region__tracker.cc,v 1.2 2013/10/12 22:11:00 ryoon Exp $

--- extern/libmv/libmv/tracking/brute_region_tracker.cc.orig	2013-04-05 09:23:20.000000000 +0000
+++ extern/libmv/libmv/tracking/brute_region_tracker.cc
@@ -24,7 +24,7 @@
 #include <emmintrin.h>
 #endif
 
-#if !defined(__APPLE__) && !defined(__FreeBSD__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__NetBSD__)
 // Needed for memalign on Linux and _aligned_alloc on Windows.
 #ifdef FREE_WINDOWS
 /* make sure _aligned_malloc is included */
@@ -60,7 +60,7 @@ void *aligned_malloc(int size, int align
   // they work natively with SSE types with no further work.
   CHECK_EQ(alignment, 16);
   return malloc(size);
-#elif __FreeBSD__
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
   void *result;
 
   if (posix_memalign(&result, alignment, size)) {
