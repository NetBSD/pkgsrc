$NetBSD: patch-src_mrgsort.c,v 1.1 2026/01/03 10:37:18 wiz Exp $

Adapt to POSIX mergesort prototype.

--- src/mrgsort.c.orig	1998-11-25 08:06:11.000000000 +0000
+++ src/mrgsort.c
@@ -98,15 +98,15 @@ do_mergesort (unsigned char *base, unsig
  * Global functions.
  */
 
-void
-mergesort_r (void *base, unsigned int number_of_elements,
-	     unsigned int size, MergesortCompFunc comparison_func,
+int
+mergesort_r (void *base, size_t number_of_elements,
+	     size_t size, MergesortCompFunc comparison_func,
 	     void *comparison_func_context)
 {
   void *tmp;
 
   if (number_of_elements == 0)
-    return;
+    return 0;
 
   /* Allocate tmp buffer. */
   tmp = malloc (number_of_elements * size);
@@ -116,4 +116,5 @@ mergesort_r (void *base, unsigned int nu
 		comparison_func_context);
 
   free (tmp);
+  return 0;
 }
