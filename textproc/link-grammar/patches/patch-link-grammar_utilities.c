$NetBSD: patch-link-grammar_utilities.c,v 1.2 2020/04/17 01:43:41 gutteridge Exp $

Fix SunOS build.
https://github.com/opencog/link-grammar/pull/1093

--- link-grammar/utilities.c.orig	2020-02-29 01:44:12.000000000 +0000
+++ link-grammar/utilities.c
@@ -757,7 +757,7 @@ bool strtodC(const char *s, float *r)
 {
 	char *err;
 
-#ifdef HAVE_LOCALE_T
+#if defined(HAVE_LOCALE_T) && !defined(__sun__)
 	double val = strtod_l(s, &err, get_C_LC_NUMERIC());
 #else
 	/* dictionary_setup_locale() invokes setlocale(LC_NUMERIC, "C") */
