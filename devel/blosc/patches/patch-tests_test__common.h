$NetBSD: patch-tests_test__common.h,v 1.4 2018/05/13 03:22:33 minskim Exp $

Use posix_memalign on SunOS with __EXTENSIONS__.
Use a standard C11 test.
Prefer posix_memalign over C11 aligned_alloc because we are invoking undefined
behaviour (C11 7.22.3.1).

--- tests/test_common.h.orig	2017-07-19 08:08:12.000000000 +0000
+++ tests/test_common.h
@@ -61,16 +61,15 @@ static void* blosc_test_malloc(const siz
   const int32_t clean_value = 0x99;
   void *block = NULL;
   int32_t res = 0;
-
-#if defined(_ISOC11_SOURCE) || (defined(__FreeBSD__) && __STDC_VERSION__ >= 201112L)
+#if _POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600 || defined(__EXTENSIONS__)
+  /* Platform does have an implementation of posix_memalign */
+  res = posix_memalign(&block, alignment, size);
+#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L && !defined(__APPLE__)
   /* C11 aligned allocation. 'size' must be a multiple of the alignment. */
   block = aligned_alloc(alignment, size);
 #elif defined(_WIN32)
   /* A (void *) cast needed for avoiding a warning with MINGW :-/ */
   block = (void *)_aligned_malloc(size, alignment);
-#elif _POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600
-  /* Platform does have an implementation of posix_memalign */
-  res = posix_memalign(&block, alignment, size);
 #elif defined(__APPLE__)
   /* Mac OS X guarantees 16-byte alignment in small allocs */
   block = malloc(size);
