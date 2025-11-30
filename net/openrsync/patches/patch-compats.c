$NetBSD: patch-compats.c,v 1.1 2025/11/30 11:46:38 vins Exp $

Prevent incompatble pointer types for memset. 

--- compats.c.orig	2025-01-27 04:36:41.000000000 +0000
+++ compats.c
@@ -2145,7 +2145,7 @@ explicit_bzero(void *p, size_t n)
  * Indirect memset through a volatile pointer to hopefully avoid
  * dead-store optimisation eliminating the call.
  */
-static void (* volatile ssh_memset)(void *, int, size_t) = memset;
+static void * (* ssh_memset)(void *, int, size_t) = memset;
 
 void
 explicit_bzero(void *p, size_t n)
