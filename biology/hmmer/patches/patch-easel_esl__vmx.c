$NetBSD: patch-easel_esl__vmx.c,v 1.1 2024/04/22 13:44:10 he Exp $

Compiling with -maltivec defines __APPLE_ALTIVEC__, but
we still need <altivec.h> included(!)

--- easel/esl_vmx.c.orig	2010-03-28 14:35:26.000000000 +0000
+++ easel/esl_vmx.c
@@ -30,7 +30,7 @@
 #include <math.h>
 #include <float.h>
 
-#ifndef __APPLE_ALTIVEC__
+#if !defined(__APPLE_ALTIVEC__) || defined(__NetBSD__)
 #include <altivec.h>
 #endif
 
