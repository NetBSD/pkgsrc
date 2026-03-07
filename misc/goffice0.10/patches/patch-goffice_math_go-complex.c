$NetBSD: patch-goffice_math_go-complex.c,v 1.3 2026/03/07 11:00:59 bsiegert Exp $

Format string is passed in as argument.

--- goffice/math/go-complex.c.orig	2026-02-11 02:06:20.000000000 +0000
+++ goffice/math/go-complex.c
@@ -36,6 +36,8 @@
 #define COMPLEX SUFFIX(GOComplex)
 
 /* ------------------------------------------------------------------------- */
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
 
 static COMPLEX *
 SUFFIX(go_complex_dup) (COMPLEX *src)
@@ -131,6 +133,7 @@ SUFFIX(go_complex_to_string) (COMPLEX co
 
 	return res;
 }
+#pragma GCC diagnostic pop
 
 /* ------------------------------------------------------------------------- */
 
