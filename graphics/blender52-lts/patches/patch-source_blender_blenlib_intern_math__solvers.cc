$NetBSD: patch-source_blender_blenlib_intern_math__solvers.cc,v 1.1 2026/11/08 16:15:19 ryoon Exp $

--- source/blender/blenlib/intern/math_solvers.cc.orig	2026-09-13 05:56:02.110635427 +0000
+++ source/blender/blenlib/intern/math_solvers.cc
@@ -98,7 +98,7 @@ bool BLI_tridiagonal_solve(
 
   MEM_delete(c1);
 
-  return isfinite(x_prev);
+  return std::isfinite(x_prev);
 }
 
 bool BLI_tridiagonal_solve_cyclic(
@@ -112,7 +112,7 @@ bool BLI_tridiagonal_solve_cyclic(
   if (count == 1) {
     r_x[0] = d[0] / (a[0] + b[0] + c[0]);
 
-    return isfinite(r_x[0]);
+    return std::isfinite(r_x[0]);
   }
 
   /* Degenerate case that works but can be simplified. */
