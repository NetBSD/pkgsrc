$NetBSD: patch-src_nmath_pnchisq.c,v 1.1 2013/08/13 19:53:30 markd Exp $

No expl() in NetBSD 6.x.

--- src/nmath/pnchisq.c.orig	2013-03-05 23:02:41.000000000 +0000
+++ src/nmath/pnchisq.c
@@ -27,7 +27,11 @@
  */
 
 #ifdef HAVE_LONG_DOUBLE
+#ifdef __NetBSD__
+# define EXP exp
+#else
 # define EXP expl
+#endif
 # define FABS fabsl
 #else
 # define EXP exp
