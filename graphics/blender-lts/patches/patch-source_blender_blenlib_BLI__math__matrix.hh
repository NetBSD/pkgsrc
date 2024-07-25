$NetBSD: patch-source_blender_blenlib_BLI__math__matrix.hh,v 1.1 2024/07/25 06:00:38 ryoon Exp $

--- source/blender/blenlib/BLI_math_matrix.hh.orig	2024-07-02 09:39:52.837279764 +0000
+++ source/blender/blenlib/BLI_math_matrix.hh
@@ -862,7 +862,7 @@ template<typename T> QuaternionBase<T> n
 template<typename T> QuaternionBase<T> normalized_to_quat_with_checks(const MatBase<T, 3, 3> &mat)
 {
   const T det = math::determinant(mat);
-  if (UNLIKELY(!isfinite(det))) {
+  if (UNLIKELY(!std::isfinite(det))) {
     return QuaternionBase<T>::identity();
   }
   else if (UNLIKELY(det < T(0))) {
