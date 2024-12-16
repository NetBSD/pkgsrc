$NetBSD: patch-tests_test__common.h,v 1.2 2024/12/16 11:05:02 jperkin Exp $

XXX: this should be detected properly, but has a habit of breaking.

--- tests/test_common.h.orig	2023-05-18 16:04:38.000000000 +0000
+++ tests/test_common.h
@@ -72,7 +72,7 @@ inline static void* blosc_test_malloc(co
 #elif defined(_WIN32)
   /* A (void *) cast needed for avoiding a warning with MINGW :-/ */
   block = (void *)_aligned_malloc(size, alignment);
-#elif _POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600
+#elif defined(__NetBSD__) || defined(__illumos__) || _POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600
   /* Platform does have an implementation of posix_memalign */
   res = posix_memalign(&block, alignment, size);
 #elif defined(__APPLE__)
