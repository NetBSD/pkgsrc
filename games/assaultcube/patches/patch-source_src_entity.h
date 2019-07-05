$NetBSD: patch-source_src_entity.h,v 1.1 2019/07/05 08:01:31 nia Exp $

[PATCH] fix some errors and warnings for GCC 6

- do not use std::abs() because math.h includes one, that converts ints
  to double. Use own iabs(), which directly uses labs() instead.
- don't use the word "gamma" as name for variables
- don't use a homebrew round() function

https://github.com/assaultcube/AC/commit/752950989b4e286459ca9aee3d61a868d7b20fa4

--- source/src/entity.h.orig	2013-10-22 18:57:16.000000000 +0000
+++ source/src/entity.h
@@ -540,7 +540,7 @@ public:
     {
         const int maxskin[2] = { 4, 6 };
         t = team_base(t < 0 ? team : t);
-        nextskin[t] = abs(s) % maxskin[t];
+        nextskin[t] = iabs(s) % maxskin[t];
     }
 };
 
