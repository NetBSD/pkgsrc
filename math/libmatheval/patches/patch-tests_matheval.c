$NetBSD: patch-tests_matheval.c,v 1.1 2016/09/15 16:39:17 wiz Exp $

Define is not defined even if scm_t_bits exists.

--- tests/matheval.c.orig	2013-08-14 20:22:08.000000000 +0000
+++ tests/matheval.c
@@ -26,10 +26,6 @@
 #include <matheval.h>
 #include "config.h"
 
-#ifndef HAVE_SCM_T_BITS
-typedef long    scm_t_bits;
-#endif
-
 #ifndef HAVE_SCM_NUM2DBL
 #ifdef SCM_NUM2DBL
 #define scm_num2dbl(x,s) SCM_NUM2DBL(x)
