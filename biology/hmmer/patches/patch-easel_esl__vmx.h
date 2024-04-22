$NetBSD: patch-easel_esl__vmx.h,v 1.1 2024/04/22 13:44:10 he Exp $

Compiling with -maltivec defines __APPLE_ALTIVEC__, but
we still need <altivec.h> included(!)

--- easel/esl_vmx.h.orig	2010-03-28 14:35:29.000000000 +0000
+++ easel/esl_vmx.h
@@ -8,7 +8,7 @@
 #include "easel.h"
 
 #include <stdio.h>
-#ifndef __APPLE_ALTIVEC__
+#if  !defined(__APPLE_ALTIVEC__) || defined(__NetBSD__)
 #include <altivec.h>
 #endif
 
