$NetBSD: patch-src-IL_include_altivec__common.h,v 1.1 2022/09/24 21:06:42 he Exp $

Use <altivec.h> if __ALTIVEC__ is defined.

--- ./src-IL/include/altivec_common.h.orig	2009-03-08 07:10:08.000000000 +0000
+++ ./src-IL/include/altivec_common.h
@@ -8,6 +8,10 @@
 
 #include "il_internal.h"
 
+#ifdef __ALTIVEC__
+#include <altivec.h>
+#endif
+
 #ifdef ALTIVEC_GCC
 #ifndef ALTIVEC_COMMON
 #define ALTIVEC_COMMON
