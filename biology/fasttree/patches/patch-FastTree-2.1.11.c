$NetBSD: patch-FastTree-2.1.11.c,v 1.1 2024/12/04 13:38:32 bacon Exp $

# Ensure assumed alignment

--- FastTree-2.1.11.c.orig	2024-12-03 14:56:25.897785201 +0000
+++ FastTree-2.1.11.c
@@ -8782,7 +8782,7 @@ double pnorm(double x)
 
 void *mymalloc(size_t sz) {
   if (sz == 0) return(NULL);
-  void *new = malloc(sz);
+  void *new = aligned_alloc(16, sz);
   if (new == NULL) {
     fprintf(stderr, "Out of memory\n");
     exit(1);
