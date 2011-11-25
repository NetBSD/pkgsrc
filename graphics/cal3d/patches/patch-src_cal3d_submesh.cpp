$NetBSD: patch-src_cal3d_submesh.cpp,v 1.1 2011/11/25 21:56:18 joerg Exp $

--- src/cal3d/submesh.cpp.orig	2011-11-25 16:04:52.000000000 +0000
+++ src/cal3d/submesh.cpp
@@ -19,6 +19,7 @@
 #include "cal3d/submesh.h"
 #include "cal3d/error.h"
 #include "cal3d/coresubmesh.h"
+#include <cstring>
 
  /*****************************************************************************/
 /** Constructs the submesh instance.
