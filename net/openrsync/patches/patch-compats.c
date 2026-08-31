$NetBSD: patch-compats.c,v 1.2 2026/08/31 14:02:05 vins Exp $

Prevent incompatble pointer types for memset. 

--- compats.c.orig	2026-07-30 04:55:04.000000000 +0000
+++ compats.c
@@ -2145,7 +2145,7 @@ explicit_bzero(void *p, size_t n)
  * Indirect memset through a volatile pointer to hopefully avoid
  * dead-store optimisation eliminating the call.
  */
-static void * (* volatile ssh_memset)(void *, int, size_t) = memset;
+static void * (* ssh_memset)(void *, int, size_t) = memset;
 
 void
 explicit_bzero(void *p, size_t n)
