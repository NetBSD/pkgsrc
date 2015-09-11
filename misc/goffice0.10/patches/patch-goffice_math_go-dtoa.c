$NetBSD: patch-goffice_math_go-dtoa.c,v 1.3 2015/09/11 21:37:00 he Exp $

Use frexp() as a substitute for frexpl() on NetBSD before 6.99.17.

--- goffice/math/go-dtoa.c.orig	2014-10-27 23:55:13.000000000 +0000
+++ goffice/math/go-dtoa.c
@@ -43,6 +43,14 @@ typedef GString FAKE_FILE;
 #define go_finitel isfinite
 #endif
 
+#if defined(__NetBSD__) 
+#if (__NetBSD_Version__ >= 699001700)
+/* in <math.h> in newer NetBSDs, should already be included */
+#else
+/* OK, this will lose precision and range, but what else to do? */
+#define frexpl(ldv,i)	(long double)frexp((double)ldv, i)
+#endif
+#endif /* __NetBSD__ */
 
 /* musl code starts here */
 
