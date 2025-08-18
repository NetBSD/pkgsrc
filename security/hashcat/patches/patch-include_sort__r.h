$NetBSD: patch-include_sort__r.h,v 1.4 2025/08/18 15:02:40 adam Exp $

Fix build on NetBSD.

--- include/sort_r.h.orig	2025-08-01 21:03:55.000000000 +0000
+++ include/sort_r.h
@@ -138,7 +138,7 @@ static _SORT_R_INLINE void sort_r_simple
 
   /* Declare structs and functions */
 
-  #if defined _SORT_R_BSD && !defined(qsort_r)
+  #if defined _SORT_R_BSD && !defined(qsort_r) && !defined(__NetBSD__)
 
     /* Ensure qsort_r is defined */
     extern void qsort_r(void *base, size_t nel, size_t width, void *thunk,
