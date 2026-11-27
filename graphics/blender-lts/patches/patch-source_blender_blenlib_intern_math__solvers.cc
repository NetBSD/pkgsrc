$NetBSD: patch-source_blender_blenlib_intern_math__solvers.cc,v 1.1 2026/11/27 13:46:28 adam Exp $

--- source/blender/blenlib/intern/math_solvers.cc.orig	2026-08-26 11:26:36.903951999 +0000
+++ source/blender/blenlib/intern/math_solvers.cc
@@ -85,7 +85,7 @@ bool BLI_tridiagonal_solve(
 
   MEM_freeN(c1);
 
-  return isfinite(x_prev);
+  return std::isfinite(x_prev);
 }
 
 bool BLI_tridiagonal_solve_cyclic(
@@ -99,7 +99,7 @@ bool BLI_tridiagonal_solve_cyclic(
   if (count == 1) {
     r_x[0] = d[0] / (a[0] + b[0] + c[0]);
 
-    return isfinite(r_x[0]);
+    return std::isfinite(r_x[0]);
   }
 
   /* Degenerate case that works but can be simplified. */
