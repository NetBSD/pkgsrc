$NetBSD: patch-tests_test__common.h,v 1.1 2023/05/29 16:38:23 wiz Exp $

--- tests/test_common.h.orig	2023-05-18 16:04:38.000000000 +0000
+++ tests/test_common.h
@@ -72,7 +72,7 @@ inline static void* blosc_test_malloc(co
 #elif defined(_WIN32)
   /* A (void *) cast needed for avoiding a warning with MINGW :-/ */
   block = (void *)_aligned_malloc(size, alignment);
-#elif _POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600
+#elif defined(__NetBSD__) || _POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600
   /* Platform does have an implementation of posix_memalign */
   res = posix_memalign(&block, alignment, size);
 #elif defined(__APPLE__)
