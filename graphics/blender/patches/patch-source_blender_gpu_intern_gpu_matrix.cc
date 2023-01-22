$NetBSD: patch-source_blender_gpu_intern_gpu_matrix.cc,v 1.2 2023/01/22 21:24:37 ryoon Exp $

Fix wrong namespace issues.

--- source/blender/gpu/intern/gpu_matrix.cc.orig	2022-11-04 00:33:07.000000000 +0000
+++ source/blender/gpu/intern/gpu_matrix.cc
@@ -103,7 +103,7 @@ static void checkmat(cosnt float *m)
 #  if _MSC_VER
     BLI_assert(_finite(m[i]));
 #  else
-    BLI_assert(!isinf(m[i]));
+    BLI_assert(!std::isinf(m[i]));
 #  endif
   }
 }
@@ -528,7 +528,7 @@ bool GPU_matrix_unproject_3fv(const floa
   const bool is_persp = proj[3][3] == 0.0f;
   if (is_persp) {
     out[2] = proj[3][2] / (proj[2][2] + in[2]);
-    if (isinf(out[2])) {
+    if (std::isinf(out[2])) {
       out[2] = FLT_MAX;
     }
     out[0] = out[2] * ((proj[2][0] + in[0]) / proj[0][0]);
