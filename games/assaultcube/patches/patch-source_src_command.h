$NetBSD: patch-source_src_command.h,v 1.1 2019/07/05 08:01:31 nia Exp $

[PATCH] fix some errors and warnings for GCC 6

- do not use std::abs() because math.h includes one, that converts ints
  to double. Use own iabs(), which directly uses labs() instead.
- don't use the word "gamma" as name for variables
- don't use a homebrew round() function

https://github.com/assaultcube/AC/commit/752950989b4e286459ca9aee3d61a868d7b20fa4

--- source/src/command.h.orig	2013-10-22 18:57:19.000000000 +0000
+++ source/src/command.h
@@ -86,6 +86,7 @@ enum { IEXC_CORE = 0, IEXC_CFG, IEXC_PRO
 #define VARNP(name, global, min, cur, max) int global = variable(#name, min, cur, max, &global, NULL, true)
 #define VARF(name, min, cur, max, body)  extern int name; void var_##name() { body; } int name = variable(#name, min, cur, max, &name, var_##name, false)
 #define VARFP(name, min, cur, max, body) extern int name; void var_##name() { body; } int name = variable(#name, min, cur, max, &name, var_##name, true)
+#define VARNFP(name, global, min, cur, max, body) extern int global; void var_##name() { body; } int global = variable(#name, min, cur, max, &global, var_##name, true)
 
 #define FVARP(name, min, cur, max) float name = fvariable(#name, min, cur, max, &name, NULL, true)
 #define FVAR(name, min, cur, max)  float name = fvariable(#name, min, cur, max, &name, NULL, false)
