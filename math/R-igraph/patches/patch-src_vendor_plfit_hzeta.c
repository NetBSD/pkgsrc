$NetBSD: patch-src_vendor_plfit_hzeta.c,v 1.2 2022/05/03 00:24:20 mef Exp $

/* tweak the macro, not found in NetBSD as of 9.99.96  */
/* corrected by tnn. thanks */

--- src/vendor/plfit/hzeta.c.orig	2022-04-20 01:23:25.000000000 +0900
+++ src/vendor/plfit/hzeta.c	2022-04-29 00:33:15.125029161 +0900
@@ -64,6 +64,12 @@
 #define M_LOG2E    1.44269504088896340735992468100      /* log_2 (e) */
 #endif
 
+/* tweak the macro, not found in NetBSD as of 9.99.96  */
+#ifdef __NetBSD__
+#define log1pl(x) logl(1.0f+(x))
+#define expm1l(x) (expl(x) - 1.0f)
+#endif
+
 /* imported from gsl_sf_result.h */
 
 struct gsl_sf_result_struct {
