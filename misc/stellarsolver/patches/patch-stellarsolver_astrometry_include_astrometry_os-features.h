$NetBSD: patch-stellarsolver_astrometry_include_astrometry_os-features.h,v 1.1 2026/05/03 06:38:33 wiz Exp $

https://github.com/rlancaste/stellarsolver/issues/150

--- stellarsolver/astrometry/include/astrometry/os-features.h.orig	2025-05-25 04:36:42.000000000 +0000
+++ stellarsolver/astrometry/include/astrometry/os-features.h
@@ -108,22 +108,8 @@
    -Ubuntu 8.10
 */
 
-#if NEED_DECLARE_QSORT_R
-//// NOTE: this declaration must match os-features-test.c .
-void qsort_r(void *base, size_t nmemb, size_t sz,
-             void *userdata,
-             int (*compar)(void *, const void *, const void *));
-#endif
-
-#if NEED_SWAP_QSORT_R
 #define QSORT_R(a,b,c,d,e) qsort_r(a,b,c,e,d)
 #define QSORT_COMPARISON_FUNCTION(func, thunk, v1, v2) func(v1, v2, thunk)
-
-#else
-#define QSORT_R qsort_r
-#define QSORT_COMPARISON_FUNCTION(func, thunk, v1, v2) func(thunk, v1, v2)
-
-#endif
 
 // As suggested in http://gcc.gnu.org/onlinedocs/gcc-4.3.0/gcc/Function-Names.html
 #if __STDC_VERSION__ < 199901L
