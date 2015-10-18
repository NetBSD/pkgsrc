$NetBSD: patch-src_hugin1_ptbatcher_BatchFrame.cpp,v 1.1 2015/10/18 15:56:56 adam Exp $

Re-order includes to fix building.

--- src/hugin1/ptbatcher/BatchFrame.cpp.orig	2015-08-24 22:47:35.000000000 +0000
+++ src/hugin1/ptbatcher/BatchFrame.cpp
@@ -24,10 +24,10 @@
  *
  */
 
+#include "FindPanoDialog.h"
 #include "BatchFrame.h"
 #include <wx/stdpaths.h>
 #include "PTBatcherGUI.h"
-#include "FindPanoDialog.h"
 #include "FailedProjectsDialog.h"
 #ifdef __WXMSW__
 #include <powrprof.h>
