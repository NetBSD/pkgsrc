$NetBSD: patch-src_core_qgsvectorlayer.h,v 1.1 2013/01/11 13:27:03 joerg Exp $

--- src/core/qgsvectorlayer.h.orig	2012-12-25 15:25:41.000000000 +0000
+++ src/core/qgsvectorlayer.h
@@ -262,7 +262,7 @@ class CORE_EXPORT QgsVectorLayer : publi
     /** write vector layer specific state to project file Dom node.
      *  @note Called by QgsMapLayer::writeXML().
      */
-    virtual bool writeXml( QDomNode & layer_node, QDomDocument & doc );
+    virtual bool writeXml( QDomNode & layer_node, QDomDocument & doc ) const;
 
     /** Read the symbology for the current layer from the Dom node supplied.
     * @param node node that will contain the symbology definition for this layer.
