$NetBSD: patch-src_hugin1_base__wx_StitchingExecutor.cpp,v 1.2 2017/07/03 20:48:03 adam Exp $

Re-order includes to fix building.

--- src/hugin1/base_wx/StitchingExecutor.cpp.orig	2017-04-29 16:05:50.000000000 +0000
+++ src/hugin1/base_wx/StitchingExecutor.cpp
@@ -34,9 +34,9 @@
 #include "hugin_base/panotools/PanoToolsUtils.h"
 #include "hugin_base/panodata/PanoramaOptions.h"
 #include "hugin_base/algorithms/basic/LayerStacks.h"
+#include "base_wx/LensTools.h"
 #include "base_wx/platform.h"
 #include "base_wx/wxPlatform.h"
-#include "base_wx/LensTools.h"
 #include "hugin/config_defaults.h"
 
 namespace HuginQueue
