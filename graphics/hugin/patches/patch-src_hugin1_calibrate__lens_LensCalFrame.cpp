$NetBSD: patch-src_hugin1_calibrate__lens_LensCalFrame.cpp,v 1.1 2015/10/18 15:56:56 adam Exp $

Re-order includes to fix building.

--- src/hugin1/calibrate_lens/LensCalFrame.cpp.orig	2015-03-15 11:43:45.000000000 +0000
+++ src/hugin1/calibrate_lens/LensCalFrame.cpp
@@ -25,6 +25,7 @@
  *
  */
 
+#include <algorithms/optimizer/PTOptimizer.h>
 #include "panoinc_WX.h"
 #include "panoinc.h"
 
@@ -36,7 +37,6 @@
 #include <wx/app.h>
 #include "LensCalApp.h"
 #include "hugin/config_defaults.h"
-#include <algorithms/optimizer/PTOptimizer.h>
 #include "lensdb/LensDB.h"
 #include "base_wx/wxLensDB.h"
 #include "panodata/StandardImageVariableGroups.h"
