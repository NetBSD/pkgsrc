$NetBSD: patch-src_hugin1_hugin_CPEditorPanel.cpp,v 1.1 2016/04/07 19:23:26 adam Exp $

Re-order includes to fix building.

--- src/hugin1/hugin/CPEditorPanel.cpp.orig	2016-02-19 22:28:54.000000000 +0000
+++ src/hugin1/hugin/CPEditorPanel.cpp
@@ -34,6 +34,12 @@
 #include "panoinc.h"
 // both includes above need to come before other wx includes on OSX
 
+// more vigra include if needed
+#include "vigra/cornerdetection.hxx"
+#include "vigra/localminmax.hxx"
+#include "vigra_ext/openmp_vigra.h"
+#include "vigra_ext/Correlation.h"
+#include "vigra_ext/cms.h"
 // hugin's
 #include "hugin/huginApp.h"
 #include "hugin/config_defaults.h"
@@ -54,12 +60,6 @@
 #include <float.h>
 #include <vector>
 
-// more vigra include if needed
-#include "vigra/cornerdetection.hxx"
-#include "vigra/localminmax.hxx"
-#include "vigra_ext/openmp_vigra.h"
-#include "vigra_ext/Correlation.h"
-#include "vigra_ext/cms.h"
 
 // Celeste header
 #include "Celeste.h"
