$NetBSD: patch-src_nmath_dnbeta.c,v 1.2 2013/12/15 19:58:11 asau Exp $

No logl() in NetBSD 6.x and FreeBSD 9.

--- src/nmath/dnbeta.c.orig	2013-03-05 23:02:41.000000000 +0000
+++ src/nmath/dnbeta.c
@@ -118,7 +118,7 @@ double dnbeta(double x, double a, double
 	sum += term;
     } while (term > sum * eps);
 
-#ifdef HAVE_LONG_DOUBLE
+#if defined(HAVE_LONG_DOUBLE) && ! defined(__NetBSD__) && ! defined(__FreeBSD__)
     return R_D_exp((double)(p_k + logl(sum)));
 #else
     return R_D_exp((double)(p_k + log(sum)));
