$NetBSD: patch-src_hugin1_hugin_GLPreviewFrame.cpp,v 1.3 2021/01/09 21:17:37 adam Exp $

Re-order includes to fix building.

--- src/hugin1/hugin/GLPreviewFrame.cpp.orig	2020-10-27 17:24:30.000000000 +0000
+++ src/hugin1/hugin/GLPreviewFrame.cpp
@@ -35,6 +35,8 @@
 #include "panoinc.h"
 #include <wx/msgdlg.h>
 
+#include "vigra_ext/InterestPoints.h"
+#include "vigra_ext/Correlation.h"
 #include "base_wx/platform.h"
 #include "base_wx/wxPlatform.h"
 #include "base_wx/LensTools.h"
@@ -59,8 +61,6 @@
 #include "hugin/PanoOperation.h"
 #include "hugin/PanoOutputDialog.h"
 #include "base_wx/PTWXDlg.h"
-#include "vigra_ext/InterestPoints.h"
-#include "vigra_ext/Correlation.h"
 #include "algorithms/control_points/CleanCP.h"
 #include "hugin_utils/openmp_lock.h"
 
