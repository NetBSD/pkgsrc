$NetBSD: patch-go_cspline.c,v 1.1 2013/03/14 18:56:07 drochner Exp $

upstream commit 01f93869b7e2e9b38bd62c94d9d71103dffa4f08

--- goffice/math/go-cspline.c.orig	2013-02-23 23:20:13.000000000 +0000
+++ goffice/math/go-cspline.c
@@ -229,9 +229,9 @@ SUFFIX(go_cspline_ref) (GOCSpline *sp)
 
 GType
 #ifdef LONG_DOUBLE
-go_cspline_get_type (void)
-#else
 go_csplinel_get_type (void)
+#else
+go_cspline_get_type (void)
 #endif
 {
 	static GType t = 0;
@@ -239,9 +239,9 @@ go_csplinel_get_type (void)
 	if (t == 0) {
 		t = g_boxed_type_register_static (
 #ifdef LONG_DOUBLE
-		     "GOCSpline",
-#else
 		     "GOCSplinel",
+#else
+		     "GOCSpline",
 #endif
 			 (GBoxedCopyFunc)SUFFIX(go_cspline_ref),
 			 (GBoxedFreeFunc)SUFFIX(go_cspline_destroy));
