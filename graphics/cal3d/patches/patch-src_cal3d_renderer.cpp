$NetBSD: patch-src_cal3d_renderer.cpp,v 1.1 2011/11/25 21:56:18 joerg Exp $

--- src/cal3d/renderer.cpp.orig	2011-11-25 16:04:28.000000000 +0000
+++ src/cal3d/renderer.cpp
@@ -28,6 +28,7 @@
 #include "cal3d/corematerial.h"
 #include "cal3d/coresubmesh.h"
 #include "cal3d/physique.h"
+#include <cstring>
 
  /*****************************************************************************/
 /** Constructs the renderer instance.
