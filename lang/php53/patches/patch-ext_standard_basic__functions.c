$NetBSD: patch-ext_standard_basic__functions.c,v 1.2 2013/07/12 00:07:04 taca Exp $

Work around VAX FP lack of INF

--- ext/standard/basic_functions.c.orig	2013-07-10 17:43:08.000000000 +0000
+++ ext/standard/basic_functions.c
@@ -3525,7 +3525,7 @@ PHPAPI double php_get_nan(void) /* {{{ *
 
 PHPAPI double php_get_inf(void) /* {{{ */
 {
-#if HAVE_HUGE_VAL_INF
+#if defined(HAVE_HUGE_VAL_INF) || defined(__vax__)
 	return HUGE_VAL;
 #elif defined(__i386__) || defined(_X86_) || defined(ALPHA) || defined(_ALPHA) || defined(__alpha)
 	double val = 0.0;
