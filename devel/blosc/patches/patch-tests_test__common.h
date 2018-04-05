$NetBSD: patch-tests_test__common.h,v 1.1 2018/04/05 09:33:48 jperkin Exp $

Use posix_memalign on SunOS with __EXTENSIONS__.

--- tests/test_common.h.orig	2017-07-19 08:08:12.000000000 +0000
+++ tests/test_common.h
@@ -68,7 +68,7 @@ static void* blosc_test_malloc(const siz
 #elif defined(_WIN32)
   /* A (void *) cast needed for avoiding a warning with MINGW :-/ */
   block = (void *)_aligned_malloc(size, alignment);
-#elif _POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600
+#elif _POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600 || defined(__EXTENSIONS__)
   /* Platform does have an implementation of posix_memalign */
   res = posix_memalign(&block, alignment, size);
 #elif defined(__APPLE__)
