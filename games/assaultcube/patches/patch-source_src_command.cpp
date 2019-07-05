$NetBSD: patch-source_src_command.cpp,v 1.1 2019/07/05 08:01:31 nia Exp $

[PATCH] fix some errors and warnings for GCC 6

- do not use std::abs() because math.h includes one, that converts ints
  to double. Use own iabs(), which directly uses labs() instead.
- don't use the word "gamma" as name for variables
- don't use a homebrew round() function

https://github.com/assaultcube/AC/commit/752950989b4e286459ca9aee3d61a868d7b20fa4

--- source/src/command.cpp.orig	2013-11-09 18:48:58.000000000 +0000
+++ source/src/command.cpp
@@ -497,7 +497,7 @@ char *executeret(const char *p)         
             if(lc<=seer_t1.length())
             {
                 int dt = seer_t1[seer_index] - seer_t1[lc];
-                if(abs(dt)<2)
+                if(iabs(dt)<2)
                 {
                     conoutf("SCRIPT EXECUTION warning [%d:%s]", &p, p);
                     seer_t2.add(seer_t1[seer_index]);
