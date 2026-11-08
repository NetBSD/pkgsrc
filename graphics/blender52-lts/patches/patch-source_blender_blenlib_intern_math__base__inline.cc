$NetBSD: patch-source_blender_blenlib_intern_math__base__inline.cc,v 1.1 2026/11/08 16:15:18 ryoon Exp $

--- source/blender/blenlib/intern/math_base_inline.cc.orig	2026-06-03 13:03:49.000000000 +0000
+++ source/blender/blenlib/intern/math_base_inline.cc
@@ -10,7 +10,7 @@
 
 #include <float.h>
 #include <limits.h>
-#include <math.h>
+#include <cmath>
 #include <stdio.h>
 #include <stdlib.h>
 
@@ -474,7 +474,7 @@ MINLINE float increment_ulp(const float value)
 
 MINLINE float increment_ulp(const float value)
 {
-  if (!isfinite(value)) {
+  if (!std::isfinite(value)) {
     return value;
   }
 
@@ -499,7 +499,7 @@ MINLINE float decrement_ulp(const float value)
 
 MINLINE float decrement_ulp(const float value)
 {
-  if (!isfinite(value)) {
+  if (!std::isfinite(value)) {
     return value;
   }
 
