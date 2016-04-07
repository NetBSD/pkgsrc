$NetBSD: patch-src_hugin1_hugin_GLPreviewFrame.cpp,v 1.1 2016/04/07 19:23:26 adam Exp $

Re-order includes to fix building.

--- src/hugin1/hugin/GLPreviewFrame.cpp.orig	2016-02-19 22:31:49.000000000 +0000
+++ src/hugin1/hugin/GLPreviewFrame.cpp
@@ -41,6 +41,8 @@
 #include "panoinc_WX.h"
 #include "panoinc.h"
 
+#include "vigra_ext/InterestPoints.h"
+#include "vigra_ext/Correlation.h"
 #include "base_wx/platform.h"
 #include "base_wx/wxPlatform.h"
 #include "base_wx/LensTools.h"
@@ -65,8 +67,6 @@
 #include "hugin/PanoOperation.h"
 #include "hugin/PanoOutputDialog.h"
 #include "base_wx/PTWXDlg.h"
-#include "vigra_ext/InterestPoints.h"
-#include "vigra_ext/Correlation.h"
 #include "algorithms/control_points/CleanCP.h"
 #include "hugin_utils/openmp_lock.h"
 
