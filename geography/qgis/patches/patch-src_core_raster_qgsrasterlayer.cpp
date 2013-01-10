$NetBSD: patch-src_core_raster_qgsrasterlayer.cpp,v 1.1 2013/01/10 23:58:30 joerg Exp $

--- src/core/raster/qgsrasterlayer.cpp.orig	2012-12-25 15:27:13.000000000 +0000
+++ src/core/raster/qgsrasterlayer.cpp
@@ -3504,7 +3504,7 @@ bool QgsRasterLayer::writeSymbology( QDo
  *  @note Called by QgsMapLayer::writeXML().
  */
 bool QgsRasterLayer::writeXml( QDomNode & layer_node,
-                               QDomDocument & document )
+                               QDomDocument & document ) const
 {
   // first get the layer element so that we can append the type attribute
 
