$NetBSD: patch-goffice_math_go-dtoa.c,v 1.1 2015/08/04 11:58:51 he Exp $

Ensure frexpl() is declared on NetBSD before 6.99.17.

--- goffice/math/go-dtoa.c.orig	2014-04-30 00:44:52.000000000 +0000
+++ goffice/math/go-dtoa.c
@@ -43,6 +43,13 @@ typedef GString FAKE_FILE;
 #define go_finitel isfinite
 #endif
 
+#if defined(__NetBSD__) 
+#if (__NetBSD_Version__ <= 699001700)
+/* in <math.h> in newer NetBSDs, should already be included */
+#else
+extern long double frexpl(long double, int*);
+#endif
+#endif /* __NetBSD__ */
 
 /* musl code starts here */
 
