$NetBSD: patch-source_blender_gpu_intern_gpu__matrix.cc,v 1.1 2026/11/08 16:15:19 ryoon Exp $

--- source/blender/gpu/intern/gpu_matrix.cc.orig	2026-09-13 20:48:26.644315359 +0000
+++ source/blender/gpu/intern/gpu_matrix.cc
@@ -104,7 +104,7 @@ static void checkmat(cosnt float *m)
 #  if _MSC_VER
     BLI_assert(_finite(m[i]));
 #  else
-    BLI_assert(!isinf(m[i]));
+    BLI_assert(!std::isinf(m[i]));
 #  endif
   }
 }
@@ -529,7 +529,7 @@ bool GPU_matrix_unproject_3fv(const float win[3],
   const bool is_persp = proj[3][3] == 0.0f;
   if (is_persp) {
     out[2] = proj[3][2] / (proj[2][2] + in[2]);
-    if (isinf(out[2])) {
+    if (std::isinf(out[2])) {
       out[2] = FLT_MAX;
     }
     out[0] = out[2] * ((proj[2][0] + in[0]) / proj[0][0]);
