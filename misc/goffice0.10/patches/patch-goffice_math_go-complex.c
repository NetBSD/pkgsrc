$NetBSD: patch-goffice_math_go-complex.c,v 1.2 2017/10/03 12:44:05 wiz Exp $

Format string is passed in as argument.

--- goffice/math/go-complex.c.orig	2016-03-24 21:19:04.000000000 +0000
+++ goffice/math/go-complex.c
@@ -87,6 +87,8 @@ MAKE_BOXED_TYPE(go_complex_get_type, "GO
 #endif
 
 /* ------------------------------------------------------------------------- */
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wformat-nonliteral"
 
 char *
 SUFFIX(go_complex_to_string) (COMPLEX const *src, char const *reformat,
@@ -132,6 +134,7 @@ SUFFIX(go_complex_to_string) (COMPLEX co
 
 	return res;
 }
+#pragma GCC diagnostic pop
 
 /* ------------------------------------------------------------------------- */
 
