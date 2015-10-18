$NetBSD: patch-src_hugin1_base__wx_wxPanoCommand.cpp,v 1.1 2015/10/18 15:56:56 adam Exp $

Re-order includes to fix building.

--- src/hugin1/base_wx/wxPanoCommand.cpp.orig	2015-08-24 21:37:12.000000000 +0000
+++ src/hugin1/base_wx/wxPanoCommand.cpp
@@ -32,14 +32,14 @@
 #include "wxPlatform.h"
 #include "LensTools.h"
 
+#include <vigra/cornerdetection.hxx>
+#include <vigra/localminmax.hxx>
+
 #include "wxImageCache.h"
 #include "platform.h"
 #include "wxPanoCommand.h"
 #include "HFOVDialog.h"
 #include <panodata/OptimizerSwitches.h>
-
-#include <vigra/cornerdetection.hxx>
-#include <vigra/localminmax.hxx>
 #include <panodata/StandardImageVariableGroups.h>
 
 #include <hugin_utils/alphanum.h>
