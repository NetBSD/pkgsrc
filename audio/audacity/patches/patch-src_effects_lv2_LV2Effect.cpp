$NetBSD: patch-src_effects_lv2_LV2Effect.cpp,v 1.1 2018/02/08 07:28:58 mrg Exp $

GCC 6 wants std namespace, found via <cmath>.

--- src/effects/lv2/LV2Effect.cpp.orig	2016-01-13 14:31:24.000000000 +0000
+++ src/effects/lv2/LV2Effect.cpp	2018-02-07 10:20:15.597051982 +0000
@@ -562,13 +562,13 @@
       lilv_scale_points_free(points);
 
       // Collect the value and range info
-      ctrl.mHasLo = !isnan(minimumVals[i]);
-      ctrl.mHasHi = !isnan(maximumVals[i]);
+      ctrl.mHasLo = !std::isnan(minimumVals[i]);
+      ctrl.mHasHi = !std::isnan(maximumVals[i]);
       ctrl.mMin = ctrl.mHasLo ? minimumVals[i] : 0.0;
       ctrl.mMax = ctrl.mHasHi ? maximumVals[i] : 1.0;
       ctrl.mLo = ctrl.mMin;
       ctrl.mHi = ctrl.mMax;
-      ctrl.mDef = !isnan(defaultValues[i]) ?
+      ctrl.mDef = !std::isnan(defaultValues[i]) ?
                   defaultValues[i] :
                      ctrl.mHasLo ?
                      ctrl.mLo :
