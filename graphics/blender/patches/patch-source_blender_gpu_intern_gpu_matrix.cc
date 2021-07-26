$NetBSD: patch-source_blender_gpu_intern_gpu_matrix.cc,v 1.1 2021/07/26 05:15:15 mrg Exp $

Fix wrong namespace issues.

--- source/blender/gpu/intern/gpu_matrix.cc.orig	2021-04-21 19:02:30.000000000 -0700
+++ source/blender/gpu/intern/gpu_matrix.cc	2021-07-24 00:49:31.946566098 -0700
@@ -119,7 +119,7 @@ static void checkmat(cosnt float *m)
 #  if _MSC_VER
     BLI_assert(_finite(m[i]));
 #  else
-    BLI_assert(!isinf(m[i]));
+    BLI_assert(!std::isinf(m[i]));
 #  endif
   }
 }
@@ -541,7 +541,7 @@ bool GPU_matrix_unproject_precalc(struct
                         &precalc->dims.ymax,
                         &precalc->dims.zmin,
                         &precalc->dims.zmax);
-  if (isinf(precalc->dims.zmax)) {
+  if (std::isinf(precalc->dims.zmax)) {
     /* We cannot retrieve the actual value of the clip_end.
      * Use `FLT_MAX` to avoid nans. */
     precalc->dims.zmax = FLT_MAX;
