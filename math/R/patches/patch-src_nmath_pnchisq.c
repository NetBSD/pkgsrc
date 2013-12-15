$NetBSD: patch-src_nmath_pnchisq.c,v 1.2 2013/12/15 19:58:11 asau Exp $

No expl() in NetBSD 6.x and FreeBSD 9.

--- src/nmath/pnchisq.c.orig	2013-03-05 23:02:41.000000000 +0000
+++ src/nmath/pnchisq.c
@@ -27,7 +27,11 @@
  */
 
 #ifdef HAVE_LONG_DOUBLE
+#if defined(__NetBSD__) || defined(__FreeBSD__)
+# define EXP exp
+#else
 # define EXP expl
+#endif
 # define FABS fabsl
 #else
 # define EXP exp
