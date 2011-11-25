$NetBSD: patch-src_celengine_galaxy.cpp,v 1.1 2011/11/25 22:08:30 joerg Exp $

--- src/celengine/galaxy.cpp.orig	2011-11-25 16:20:46.000000000 +0000
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
