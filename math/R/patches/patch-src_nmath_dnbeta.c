$NetBSD: patch-src_nmath_dnbeta.c,v 1.1 2013/08/13 19:53:30 markd Exp $

No logl() in NetBSD 6.x

--- src/nmath/dnbeta.c.orig	2013-03-05 23:02:41.000000000 +0000
+++ src/nmath/dnbeta.c
@@ -118,7 +118,7 @@ double dnbeta(double x, double a, double
 	sum += term;
     } while (term > sum * eps);
 
-#ifdef HAVE_LONG_DOUBLE
+#if defined(HAVE_LONG_DOUBLE) && ! defined(__NetBSD__)
     return R_D_exp((double)(p_k + logl(sum)));
 #else
     return R_D_exp((double)(p_k + log(sum)));
