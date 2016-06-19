$NetBSD: patch-opcodes_cgen-ops.h,v 1.1 2016/06/19 16:18:28 wiz Exp $

--- opcodes/cgen-ops.h.orig	2012-04-27 20:34:26.000000000 +0000
+++ opcodes/cgen-ops.h
@@ -27,7 +27,11 @@ with this program; if not, write to the 
 
 #if defined (__GNUC__) && ! defined (SEMOPS_DEFINE_INLINE)
 #define SEMOPS_DEFINE_INLINE
-#define SEMOPS_INLINE extern inline
+#  ifdef __GNUC_STDC_INLINE__
+#  define SEMOPS_INLINE static inline
+#  else
+#  define SEMOPS_INLINE extern inline
+#  endif
 #else
 #define SEMOPS_INLINE
 #endif
@@ -298,6 +302,8 @@ extern SI TRUNCDISI (DI);
    significant and word number 0 is the most significant word.
    ??? May also wish an endian-dependent version.  Later.  */
 
+#ifndef SEMOPS_DEFINE_INLINE
+
 QI SUBWORDSIQI (SI, int);
 HI SUBWORDSIHI (SI, int);
 SI SUBWORDSFSI (SF);
@@ -314,7 +320,7 @@ SI SUBWORDTFSI (TF, int);
 UQI SUBWORDSIUQI (SI, int);
 UQI SUBWORDDIUQI (DI, int);
 
-#ifdef SEMOPS_DEFINE_INLINE
+#else
 
 SEMOPS_INLINE SF
 SUBWORDSISF (SI in)
