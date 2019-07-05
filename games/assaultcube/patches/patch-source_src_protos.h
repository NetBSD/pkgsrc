$NetBSD: patch-source_src_protos.h,v 1.1 2019/07/05 08:01:31 nia Exp $

[PATCH] fix some errors and warnings for GCC 6

- do not use std::abs() because math.h includes one, that converts ints
  to double. Use own iabs(), which directly uses labs() instead.
- don't use the word "gamma" as name for variables
- don't use a homebrew round() function

https://github.com/assaultcube/AC/commit/752950989b4e286459ca9aee3d61a868d7b20fa4

--- source/src/protos.h.orig	2013-11-09 18:48:58.000000000 +0000
+++ source/src/protos.h
@@ -1029,7 +1029,8 @@ struct servercommandline
                 {
                     demo_interm = true;
                 }
-                else if(ai > 0) maxdemos = ai; break;
+                else if(ai > 0) maxdemos = ai;
+                break;
             }
             case 'W': demopath = a; break;
             case 'r': maprot = a; break;
