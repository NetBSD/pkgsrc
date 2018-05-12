$NetBSD: patch-tests_test__common.h,v 1.2 2018/05/12 12:01:26 maya Exp $

Use posix_memalign on SunOS with __EXTENSIONS__.
Try the __STDC_VERSION__ check for C11 for everyone, not just freebsd.

--- tests/test_common.h.orig	2017-07-19 08:08:12.000000000 +0000
+++ tests/test_common.h
@@ -62,13 +62,13 @@ static void* blosc_test_malloc(const siz
   void *block = NULL;
   int32_t res = 0;
 
-#if defined(_ISOC11_SOURCE) || (defined(__FreeBSD__) && __STDC_VERSION__ >= 201112L)
+#if defined(_ISOC11_SOURCE) || (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L)
   /* C11 aligned allocation. 'size' must be a multiple of the alignment. */
   block = aligned_alloc(alignment, size);
 #elif defined(_WIN32)
   /* A (void *) cast needed for avoiding a warning with MINGW :-/ */
   block = (void *)_aligned_malloc(size, alignment);
-#elif _POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600
+#elif _POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600 || defined(__EXTENSIONS__)
   /* Platform does have an implementation of posix_memalign */
   res = posix_memalign(&block, alignment, size);
 #elif defined(__APPLE__)
