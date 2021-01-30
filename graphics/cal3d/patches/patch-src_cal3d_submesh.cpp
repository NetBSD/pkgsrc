$NetBSD: patch-src_cal3d_submesh.cpp,v 1.3 2021/01/30 09:00:57 mef Exp $

string function is not defined

--- src/cal3d/submesh.cpp.orig	2004-12-02 07:42:18.000000000 +0900
+++ src/cal3d/submesh.cpp	2021-01-30 17:34:34.617413157 +0900
@@ -15,6 +15,7 @@
 #include "cal3d/submesh.h"
 #include "cal3d/error.h"
 #include "cal3d/coresubmesh.h"
+#include <cstring>
 
 
 CalSubmesh::CalSubmesh(CalCoreSubmesh* coreSubmesh)
