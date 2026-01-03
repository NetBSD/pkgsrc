$NetBSD: patch-src_mrgsort.h,v 1.1 2026/01/03 10:37:18 wiz Exp $

Adapt to POSIX mergesort prototype.

--- src/mrgsort.h.orig	1998-11-25 08:06:11.000000000 +0000
+++ src/mrgsort.h
@@ -41,8 +41,8 @@ typedef int (*MergesortCompFunc) (const 
  * Prototypes for global functions.
  */
 
-void mergesort_r (void *base, unsigned int number_of_elements,
-		  unsigned int size, MergesortCompFunc comparison_func,
+int mergesort_r (void *base, size_t number_of_elements,
+		  size_t size, MergesortCompFunc comparison_func,
 		  void *comparison_func_context);
 
 
