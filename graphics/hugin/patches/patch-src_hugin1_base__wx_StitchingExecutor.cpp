$NetBSD: patch-src_hugin1_base__wx_StitchingExecutor.cpp,v 1.1 2015/10/18 15:56:56 adam Exp $

Re-order includes to fix building.

--- src/hugin1/base_wx/StitchingExecutor.cpp.orig	2015-08-24 21:56:49.000000000 +0000
+++ src/hugin1/base_wx/StitchingExecutor.cpp
@@ -37,9 +37,9 @@
 #include "hugin_base/panotools/PanoToolsUtils.h"
 #include "hugin_base/panodata/PanoramaOptions.h"
 #include "hugin_base/algorithms/basic/LayerStacks.h"
+#include "base_wx/LensTools.h"
 #include "base_wx/platform.h"
 #include "base_wx/wxPlatform.h"
-#include "base_wx/LensTools.h"
 #include "hugin/config_defaults.h"
 
 #if wxCHECK_VERSION(3,0,0)
