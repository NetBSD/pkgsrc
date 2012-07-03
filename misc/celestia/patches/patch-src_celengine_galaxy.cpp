$NetBSD: patch-src_celengine_galaxy.cpp,v 1.2 2012/07/03 17:40:36 joerg Exp $

--- src/celengine/galaxy.cpp.orig	2005-12-05 05:42:43.000000000 +0000
+++ src/celengine/galaxy.cpp
@@ -311,8 +311,8 @@ void Galaxy::renderGalaxyEllipsoid(const
     float discSizeInPixels = pixelSize * getRadius() / offset.length();
     unsigned int nRings = (unsigned int) (discSizeInPixels / 4.0f);
     unsigned int nSlices = (unsigned int) (discSizeInPixels / 4.0f);
-    nRings = max(nRings, 100);
-    nSlices = max(nSlices, 100);
+    nRings = max(nRings, 100U);
+    nSlices = max(nSlices, 100U);
 
     VertexProcessor* vproc = context.getVertexProcessor();
     if (vproc == NULL)
