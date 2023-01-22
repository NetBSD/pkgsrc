$NetBSD: patch-source_blender_blenkernel_intern_customdata.cc,v 1.1 2023/01/22 21:24:37 ryoon Exp $

--- source/blender/blenkernel/intern/customdata.cc.orig	2022-11-11 15:26:15.000000000 +0000
+++ source/blender/blenkernel/intern/customdata.cc
@@ -492,7 +492,7 @@ static bool layerValidate_propFloat(void
   bool has_errors = false;
 
   for (int i = 0; i < totitems; i++, fp++) {
-    if (!isfinite(fp->f)) {
+    if (!std::isfinite(fp->f)) {
       if (do_fixes) {
         fp->f = 0.0f;
       }
@@ -1556,7 +1556,7 @@ static bool layerValidate_propfloat3(voi
   float *values = static_cast<float *>(data);
   bool has_errors = false;
   for (int i = 0; i < totitems * 3; i++) {
-    if (!isfinite(values[i])) {
+    if (!std::isfinite(values[i])) {
       if (do_fixes) {
         values[i] = 0.0f;
       }
@@ -1607,7 +1607,7 @@ static bool layerValidate_propfloat2(voi
   float *values = static_cast<float *>(data);
   bool has_errors = false;
   for (int i = 0; i < totitems * 2; i++) {
-    if (!isfinite(values[i])) {
+    if (!std::isfinite(values[i])) {
       if (do_fixes) {
         values[i] = 0.0f;
       }
