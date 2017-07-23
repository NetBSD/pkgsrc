$NetBSD: patch-libfaad_common.h,v 1.1 2017/07/23 16:09:17 adam Exp $

Use correct inlines.
lrintf() returns long.

--- libfaad/common.h.orig	2017-07-06 19:16:40.000000000 +0000
+++ libfaad/common.h
@@ -41,7 +41,7 @@ extern "C" {
 
 #include "neaacdec.h"
 
-#if 1
+#if 0
 #define INLINE __inline
 #else
 #define INLINE inline
@@ -332,7 +332,7 @@ char *strchr(), *strrchr();
     #ifndef HAVE_LRINTF
     #define HAS_LRINTF
     // from http://www.stereopsis.com/FPU.html
-    static INLINE int lrintf(float f)
+    static INLINE long int lrintf(float f)
     {
         int i;
         __asm__ __volatile__ (
