$NetBSD: patch-src_vendor_cigraph_vendor_plfit_hzeta.c,v 1.1 2024/11/03 12:40:56 mef Exp $

/* tweak the macro, not found in NetBSD as of 9.99.96  */
/* corrected by tnn. thanks */

--- src/vendor/cigraph/vendor/plfit/hzeta.c.orig	2024-09-26 20:28:57.000000000 +0900
+++ src/vendor/cigraph/vendor/plfit/hzeta.c	2024-11-03 15:49:13.010904356 +0900
@@ -65,6 +65,12 @@
 #define M_LOG2E     1.44269504088896340735992468100189214
 #endif
 
+/* tweak the macro, not found in NetBSD as of 9.99.96  */
+#ifdef __NetBSD__
+#define log1pl(x) logl(1.0f+(x))
+#define expm1l(x) (expl(x) - 1.0f)
+#endif
+
 #ifndef M_LN2
 #define M_LN2       0.693147180559945309417232121458176568
 #endif
