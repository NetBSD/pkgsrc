$NetBSD: patch-source_blender_blenkernel_intern_customdata.cc,v 1.2 2024/09/06 15:43:27 prlw1 Exp $

--- source/blender/blenkernel/intern/customdata.cc.orig	2024-06-19 10:32:33.000000000 +0000
+++ source/blender/blenkernel/intern/customdata.cc
@@ -500,7 +500,7 @@ static bool layerValidate_propFloat(void
   bool has_errors = false;
 
   for (int i = 0; i < totitems; i++, fp++) {
-    if (!isfinite(fp->f)) {
+    if (!std::isfinite(fp->f)) {
       if (do_fixes) {
         fp->f = 0.0f;
       }
@@ -1395,7 +1395,7 @@ static bool layerValidate_propfloat3(voi
   float *values = static_cast<float *>(data);
   bool has_errors = false;
   for (int i = 0; i < totitems * 3; i++) {
-    if (!isfinite(values[i])) {
+    if (!std::isfinite(values[i])) {
       if (do_fixes) {
         values[i] = 0.0f;
       }
@@ -1446,7 +1446,7 @@ static bool layerValidate_propfloat2(voi
   float *values = static_cast<float *>(data);
   bool has_errors = false;
   for (int i = 0; i < totitems * 2; i++) {
-    if (!isfinite(values[i])) {
+    if (!std::isfinite(values[i])) {
       if (do_fixes) {
         values[i] = 0.0f;
       }
