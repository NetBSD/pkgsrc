$NetBSD: patch-stellarsolver_astrometry_include_astrometry_ioutils.h,v 1.1 2026/05/03 06:38:33 wiz Exp $

https://github.com/rlancaste/stellarsolver/issues/150

--- stellarsolver/astrometry/include/astrometry/ioutils.h.orig	2025-05-25 04:36:42.000000000 +0000
+++ stellarsolver/astrometry/include/astrometry/ioutils.h
@@ -28,17 +28,12 @@ char* dirname(const char* path);
 #include "astrometry/an-bool.h"
 #include "astrometry/bl.h"
 #include "astrometry/keywords.h"
+#include "astrometry/os-features.h"
 
 extern uint32_t ENDIAN_DETECTOR;
 
 void QSORT_R(void* base, size_t nmembers, size_t member_size,
-             void* token, int (*compar)(void *, const void *, const void *));
-
-/**
-   You should define the "comparison" function like this:
-   static int QSORT_COMPARISON_FUNCTION(my_comparison, void* token, const void* v1, const void* v2) {
- */
-#define QSORT_COMPARISON_FUNCTION(func, thunk, v1, v2) func(thunk, v1, v2)
+             void* token, QSORT_COMPARISON_FUNCTION(int (*compar), void *, const void *, const void *));
 
 int copy_file(const char* infn, const char* outfn);
 
