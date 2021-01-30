$NetBSD: patch-src_cal3d_hardwaremodel.cpp,v 1.2 2021/01/30 09:00:57 mef Exp $

string function is not defined


--- src/cal3d/hardwaremodel.cpp.orig	2021-01-30 17:39:48.235293991 +0900
+++ src/cal3d/hardwaremodel.cpp	2021-01-30 17:40:17.028509062 +0900
@@ -23,6 +23,7 @@
 #include "cal3d/coresubmesh.h"
 #include "cal3d/coreskeleton.h"
 #include "cal3d/skeleton.h"
+#include <cstring>
 
 
  /*****************************************************************************/
