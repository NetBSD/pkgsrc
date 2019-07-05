$NetBSD: patch-source_src_world.cpp,v 1.1 2019/07/05 08:01:31 nia Exp $

[PATCH] fix some errors and warnings for GCC 6

- do not use std::abs() because math.h includes one, that converts ints
  to double. Use own iabs(), which directly uses labs() instead.
- don't use the word "gamma" as name for variables
- don't use a homebrew round() function

https://github.com/assaultcube/AC/commit/752950989b4e286459ca9aee3d61a868d7b20fa4

--- source/src/world.cpp.orig	2013-10-22 18:57:19.000000000 +0000
+++ source/src/world.cpp
@@ -79,9 +79,9 @@ void remip(const block &b, int level)
                 || o[i]->ceil!=o[3]->ceil
                 || o[i]->ftex!=o[3]->ftex
                 || o[i]->ctex!=o[3]->ctex
-                || abs(o[i+1]->r-o[0]->r)>lighterr          // perfect mip even if light is not exactly equal
-                || abs(o[i+1]->g-o[0]->g)>lighterr
-                || abs(o[i+1]->b-o[0]->b)>lighterr
+                || iabs(o[i+1]->r-o[0]->r)>lighterr          // perfect mip even if light is not exactly equal
+                || iabs(o[i+1]->g-o[0]->g)>lighterr
+                || iabs(o[i+1]->b-o[0]->b)>lighterr
                 || o[i]->utex!=o[3]->utex
                 || o[i]->wtex!=o[3]->wtex) goto c;
             }
