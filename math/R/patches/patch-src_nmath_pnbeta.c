$NetBSD: patch-src_nmath_pnbeta.c,v 1.2 2013/12/15 19:58:11 asau Exp $

No logl() in NetBSD 6.x and FreeBSD 9.

--- src/nmath/pnbeta.c.orig	2013-03-05 23:02:41.000000000 +0000
+++ src/nmath/pnbeta.c
@@ -92,7 +92,7 @@ pnbeta2(double x, double o_x, double a, 
 
     /* return R_DT_val(ans), but we want to warn about cancellation here */
     if (lower_tail)
-#ifdef HAVE_LONG_DOUBLE
+#if defined(HAVE_LONG_DOUBLE) && ! defined(__NetBSD__) && ! defined(__FreeBSD__)
 	return (double) (log_p ? logl(ans) : ans);
 #else
 	return log_p ? log(ans) : ans;
