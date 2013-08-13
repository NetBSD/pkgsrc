$NetBSD: patch-src_library_stats_src_cov.c,v 1.1 2013/08/13 19:53:30 markd Exp $

No sqrtl() in NetBSD 6.x

--- src/library/stats/src/cov.c.orig	2013-03-05 23:02:24.000000000 +0000
+++ src/library/stats/src/cov.c
@@ -27,6 +27,10 @@
 
 #include "statsR.h"
 
+#ifdef __NetBSD__
+#define sqrtl sqrt
+#endif
+
 static SEXP corcov(SEXP x, SEXP y, SEXP na_method, SEXP kendall, Rboolean cor);
 
 
