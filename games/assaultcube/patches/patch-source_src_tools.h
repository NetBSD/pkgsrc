$NetBSD: patch-source_src_tools.h,v 1.1 2019/07/05 08:01:31 nia Exp $

[PATCH] fix some errors and warnings for GCC 6

- do not use std::abs() because math.h includes one, that converts ints
  to double. Use own iabs(), which directly uses labs() instead.
- don't use the word "gamma" as name for variables
- don't use a homebrew round() function

https://github.com/assaultcube/AC/commit/752950989b4e286459ca9aee3d61a868d7b20fa4

--- source/src/tools.h.orig	2013-10-22 18:57:19.000000000 +0000
+++ source/src/tools.h
@@ -54,8 +54,7 @@ static inline T min(T a, T b)
 {
     return a < b ? a : b;
 }
-
-static inline float round(float x) { return floor(x + 0.5f); }
+inline int iabs(int n) { return labs(n); }
 
 #define clamp(a,b,c) (max(b, min(a, c)))
 #define rnd(x) ((int)(randomMT()&0xFFFFFF)%(x))
