$NetBSD: patch-source_blender_blenkernel_intern_fcurve__driver.cc,v 1.1 2024/09/06 15:43:27 prlw1 Exp $

--- source/blender/blenkernel/intern/fcurve_driver.cc.orig	2024-06-05 11:47:56.000000000 +0000
+++ source/blender/blenkernel/intern/fcurve_driver.cc
@@ -1159,7 +1159,7 @@ static bool driver_evaluate_simple_expr(
 
   switch (status) {
     case EXPR_PYLIKE_SUCCESS:
-      if (isfinite(result_val)) {
+      if (std::isfinite(result_val)) {
         *result = float(result_val);
       }
       return true;
