$NetBSD: patch-compats.c,v 1.1 2025/10/07 08:22:39 wiz Exp $

compats.c:511:60: error: initialization of 'void (* volatile)(void *, int,  size_t)' {aka 'void (* volatile)(void *, int,  long unsigned int)'} from incompatible pointer type 'void * (*)(void *, int,  size_t)' {aka 'void * (*)(void *, int,  long unsigned int)'} [-Wincompatible-pointer-types]
  511 | static void (* volatile ssh_memset)(void *, int, size_t) = memset;
      |                                                            ^~~~~~

https://github.com/kristapsdz/lowdown/issues/167

--- compats.c.orig	2025-10-07 08:18:53.032539836 +0000
+++ compats.c
@@ -508,7 +508,7 @@ explicit_bzero(void *p, size_t n)
  * Indirect memset through a volatile pointer to hopefully avoid
  * dead-store optimisation eliminating the call.
  */
-static void (* volatile ssh_memset)(void *, int, size_t) = memset;
+static void *(* volatile ssh_memset)(void *, int, size_t) = memset;
 
 void
 explicit_bzero(void *p, size_t n)
