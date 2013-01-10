$NetBSD: patch-src_core_qgsmaplayer.cpp,v 1.1 2013/01/10 23:58:30 joerg Exp $

--- src/core/qgsmaplayer.cpp.orig	2012-12-25 15:19:10.000000000 +0000
+++ src/core/qgsmaplayer.cpp
@@ -279,7 +279,7 @@ bool QgsMapLayer::readXml( QDomNode & la
 
 
 
-bool QgsMapLayer::writeXML( QDomNode & layer_node, QDomDocument & document )
+bool QgsMapLayer::writeXML( QDomNode & layer_node, QDomDocument & document ) const
 {
   // general layer metadata
   QDomElement maplayer = document.createElement( "maplayer" );
@@ -301,7 +301,7 @@ bool QgsMapLayer::writeXML( QDomNode & l
 
   QString src = source();
 
-  QgsVectorLayer *vlayer = qobject_cast<QgsVectorLayer *>( this );
+  const QgsVectorLayer *vlayer = qobject_cast<const QgsVectorLayer *>( this );
   if ( vlayer && vlayer->providerType() == "spatialite" )
   {
     QgsDataSourceURI uri( src );
@@ -377,7 +377,7 @@ bool QgsMapLayer::writeXML( QDomNode & l
 
 
 
-bool QgsMapLayer::writeXml( QDomNode & layer_node, QDomDocument & document )
+bool QgsMapLayer::writeXml( QDomNode & layer_node, QDomDocument & document ) const
 {
   // NOP by default; children will over-ride with behavior specific to them
 
@@ -422,7 +422,7 @@ void QgsMapLayer::toggleScaleBasedVisibi
   mScaleBasedVisibility = theVisibilityFlag;
 }
 
-bool QgsMapLayer::hasScaleBasedVisibility()
+bool QgsMapLayer::hasScaleBasedVisibility() const
 {
   return mScaleBasedVisibility;
 }
@@ -432,7 +432,7 @@ void QgsMapLayer::setMinimumScale( float
   mMinScale = theMinScale;
 }
 
-float QgsMapLayer::minimumScale()
+float QgsMapLayer::minimumScale() const
 {
   return mMinScale;
 }
@@ -443,23 +443,23 @@ void QgsMapLayer::setMaximumScale( float
   mMaxScale = theMaxScale;
 }
 
-float QgsMapLayer::maximumScale()
+float QgsMapLayer::maximumScale() const
 {
   return mMaxScale;
 }
 
 
-QStringList QgsMapLayer::subLayers()
+QStringList QgsMapLayer::subLayers() const
 {
   return QStringList();  // Empty
 }
 
-void QgsMapLayer::setLayerOrder( QStringList layers )
+void QgsMapLayer::setLayerOrder( const QStringList &layers )
 {
   // NOOP
 }
 
-void QgsMapLayer::setSubLayerVisibility( QString name, bool vis )
+void QgsMapLayer::setSubLayerVisibility( const QString &name, bool vis )
 {
   // NOOP
 }
@@ -483,7 +483,7 @@ void QgsMapLayer::setCrs( const QgsCoord
     emit layerCrsChanged();
 }
 
-unsigned int QgsMapLayer::getTransparency()
+unsigned int QgsMapLayer::getTransparency() const
 {
   return mTransparencyLevel;
 }
