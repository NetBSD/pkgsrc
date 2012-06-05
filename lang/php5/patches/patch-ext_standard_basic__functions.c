$NetBSD: patch-ext_standard_basic__functions.c,v 1.1 2012/06/05 08:58:36 abs Exp $

Work around VAX FP lack of INF

--- ext/standard/basic_functions.c.orig	2010-06-19 22:23:01.000000000 +0000
+++ ext/standard/basic_functions.c
@@ -3954,7 +3954,7 @@ PHPAPI double php_get_nan(void)
 
 PHPAPI double php_get_inf(void)
 {
-#if HAVE_HUGE_VAL_INF
+#if defined(HAVE_HUGE_VAL_INF) || defined(__vax__)
 	return HUGE_VAL;
 #elif defined(__i386__) || defined(_X86_) || defined(ALPHA) || defined(_ALPHA) || defined(__alpha)
 	double val = 0.0;
