$NetBSD: patch-ext_standard_basic__functions.c,v 1.1 2014/11/24 15:37:08 taca Exp $

Work around VAX FP lack of INF

--- ext/standard/basic_functions.c.orig	2014-11-12 13:52:21.000000000 +0000
+++ ext/standard/basic_functions.c
@@ -3489,7 +3489,7 @@ PHPAPI double php_get_nan(void) /* {{{ *
 
 PHPAPI double php_get_inf(void) /* {{{ */
 {
-#if HAVE_HUGE_VAL_INF
+#if defined(HAVE_HUGE_VAL_INF) || defined(__vax__)
 	return HUGE_VAL;
 #elif defined(__i386__) || defined(_X86_) || defined(ALPHA) || defined(_ALPHA) || defined(__alpha)
 	double val = 0.0;
