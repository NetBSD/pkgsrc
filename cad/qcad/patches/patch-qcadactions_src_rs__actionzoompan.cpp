$NetBSD: patch-qcadactions_src_rs__actionzoompan.cpp,v 1.1 2011/09/23 03:26:57 ryoon Exp $

--- qcadactions/src/rs_actionzoompan.cpp.orig	2005-11-22 11:51:46.000000000 +0000
+++ qcadactions/src/rs_actionzoompan.cpp
@@ -28,6 +28,7 @@
 #include "rs_snapper.h"
 #include "rs_point.h"
 
+#include <cstdlib>
 
 RS_ActionZoomPan::RS_ActionZoomPan(RS_EntityContainer& container,
                                    RS_GraphicView& graphicView)
