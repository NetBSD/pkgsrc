$NetBSD: patch-source_blender_blenlib_intern_math__base__inline.cc,v 1.1 2026/11/27 13:46:28 adam Exp $

--- source/blender/blenlib/intern/math_base_inline.cc.orig	2026-08-26 12:19:03.836840624 +0000
+++ source/blender/blenlib/intern/math_base_inline.cc
@@ -11,7 +11,11 @@
 
 #include <float.h>
 #include <limits.h>
+#ifdef __cplusplus
+#include <cmath>
+#else
 #include <math.h>
+#endif
 #include <stdio.h>
 #include <stdlib.h>
 
@@ -514,7 +518,11 @@ MINLINE float increment_ulp(const float value)
 
 MINLINE float increment_ulp(const float value)
 {
+#ifdef __cplusplus
+  if (!std::isfinite(value)) {
+#else
   if (!isfinite(value)) {
+#endif
     return value;
   }
 
@@ -539,7 +547,11 @@ MINLINE float decrement_ulp(const float value)
 
 MINLINE float decrement_ulp(const float value)
 {
+#ifdef __cplusplus
+  if (!std::isfinite(value)) {
+#else
   if (!isfinite(value)) {
+#endif
     return value;
   }
 
