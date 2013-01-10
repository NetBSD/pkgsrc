$NetBSD: patch-src_core_qgsvectorlayer.cpp,v 1.1 2013/01/10 23:58:30 joerg Exp $

--- src/core/qgsvectorlayer.cpp.orig	2012-12-25 15:28:50.000000000 +0000
+++ src/core/qgsvectorlayer.cpp
@@ -2811,7 +2811,7 @@ bool QgsVectorLayer::setDataProvider( QS
 
 /* virtual */
 bool QgsVectorLayer::writeXml( QDomNode & layer_node,
-                               QDomDocument & document )
+                               QDomDocument & document ) const
 {
   // first get the layer element so that we can append the type attribute
 
