$NetBSD: patch-include_Inventor_C_base_math-undefs.h,v 1.1 2013/06/26 21:22:41 joerg Exp $

--- include/Inventor/C/base/math-undefs.h.orig	2013-06-26 19:21:55.000000000 +0000
+++ include/Inventor/C/base/math-undefs.h
@@ -40,6 +40,7 @@
   work as intended.  20070518 larsa
 */
 
+#if 0
 #undef cosf
 #define cosf(x) NO_SINGLEPREC /* whatever that'll give us a compile error... */
 #undef sinf
@@ -58,6 +59,7 @@
 #define atanf(x) NO_SINGLEPREC
 #undef atan2f
 #define atan2f(x) NO_SINGLEPREC
+#endif
 
 /* *********************************************************************** */
 
