$NetBSD: patch-lib_xalloc-oversized.h,v 1.1 2018/09/25 20:21:51 joerg Exp $

--- lib/xalloc-oversized.h.orig	2018-08-19 18:13:08.426109176 +0000
+++ lib/xalloc-oversized.h
@@ -35,11 +35,7 @@
 #define __xalloc_oversized(n, s) \
   ((size_t) (PTRDIFF_MAX < SIZE_MAX ? PTRDIFF_MAX : SIZE_MAX - 1) / (s) < (n))
 
-#if PTRDIFF_MAX < SIZE_MAX
-typedef ptrdiff_t __xalloc_count_type;
-#else
 typedef size_t __xalloc_count_type;
-#endif
 
 /* Return 1 if an array of N objects, each of size S, cannot exist
    reliably due to size or ptrdiff_t arithmetic overflow.  S must be
