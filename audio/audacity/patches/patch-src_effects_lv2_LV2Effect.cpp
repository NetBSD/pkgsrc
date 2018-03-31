$NetBSD: patch-src_effects_lv2_LV2Effect.cpp,v 1.2 2018/03/31 20:08:12 joerg Exp $

GCC 6 wants std namespace, found via <cmath>.

--- src/effects/lv2/LV2Effect.cpp.orig	2016-01-13 14:31:24.000000000 +0000
+++ src/effects/lv2/LV2Effect.cpp
@@ -44,6 +44,7 @@
 #include "lv2/lv2plug.in/ns/ext/buf-size/buf-size.h"
 #include "lv2/lv2plug.in/ns/ext/parameters/parameters.h"
 #include "lv2/lv2plug.in/ns/extensions/ui/ui.h"
+#include <cmath>
 
 #if defined(__WXGTK__)
 #include <gtk/gtk.h>
@@ -562,13 +563,13 @@ bool LV2Effect::SetHost(EffectHostInterf
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
