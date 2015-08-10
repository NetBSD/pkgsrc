$NetBSD: patch-goffice_math_go-complex.c,v 1.1 2015/08/10 19:30:06 joerg Exp $

Format string is passed in as argument.

--- goffice/math/go-complex.c.orig	2015-08-10 16:25:07.000000000 +0000
+++ goffice/math/go-complex.c
@@ -58,6 +58,8 @@
 #define COMPLEX SUFFIX(GOComplex)
 
 /* ------------------------------------------------------------------------- */
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
 
 char *
 SUFFIX(go_complex_to_string) (COMPLEX const *src, char const *reformat,
@@ -103,6 +105,7 @@ SUFFIX(go_complex_to_string) (COMPLEX co
 
 	return res;
 }
+#pragma GCC diagnostic pop
 
 /* ------------------------------------------------------------------------- */
 
