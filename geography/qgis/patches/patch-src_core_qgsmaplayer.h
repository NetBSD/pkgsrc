$NetBSD: patch-src_core_qgsmaplayer.h,v 1.1 2013/01/10 23:58:30 joerg Exp $

--- src/core/qgsmaplayer.h.orig	2012-12-25 15:15:57.000000000 +0000
+++ src/core/qgsmaplayer.h
@@ -127,16 +127,16 @@ class CORE_EXPORT QgsMapLayer : public Q
      * Returns the sublayers of this layer
      * (Useful for providers that manage their own layers, such as WMS)
      */
-    virtual QStringList subLayers();
+    virtual QStringList subLayers() const;
 
     /**
      * Reorders the *previously selected* sublayers of this layer from bottom to top
      * (Useful for providers that manage their own layers, such as WMS)
      */
-    virtual void setLayerOrder( QStringList layers );
+    virtual void setLayerOrder( const QStringList &layers );
 
     /** Set the visibility of the given sublayer name */
-    virtual void setSubLayerVisibility( QString name, bool vis );
+    virtual void setSubLayerVisibility( const QString &name, bool vis );
 
 
     /** True if the layer can be edited */
@@ -174,7 +174,7 @@ class CORE_EXPORT QgsMapLayer : public Q
 
        @returns true if successful
     */
-    bool writeXML( QDomNode & layer_node, QDomDocument & document );
+    bool writeXML( QDomNode & layer_node, QDomDocument & document ) const;
 
     /** Set a custom property for layer. Properties are stored in a map and saved in project file.
      *  @note Added in v1.4 */
@@ -193,7 +193,7 @@ class CORE_EXPORT QgsMapLayer : public Q
     virtual bool hasCompatibleSymbology( const QgsMapLayer& other ) const = 0;
 
     /** Accessor for transparency level. */
-    unsigned int getTransparency();
+    unsigned int getTransparency() const;
 
     /** Mutator for transparency level. Should be between 0 and 255 */
     void setTransparency( unsigned int );
@@ -318,15 +318,15 @@ class CORE_EXPORT QgsMapLayer : public Q
 
     /** Accessor and mutator for the minimum scale member */
     void setMinimumScale( float theMinScale );
-    float minimumScale();
+    float minimumScale() const;
 
     /** Accessor and mutator for the maximum scale member */
     void setMaximumScale( float theMaxScale );
-    float maximumScale();
+    float maximumScale() const;
 
     /** Accessor and mutator for the scale based visilibility flag */
     void toggleScaleBasedVisibility( bool theVisibilityFlag );
-    bool hasScaleBasedVisibility();
+    bool hasScaleBasedVisibility() const;
 
     /** Clear cached image
      * added in 1.5 */
@@ -381,7 +381,7 @@ class CORE_EXPORT QgsMapLayer : public Q
     /** called by writeXML(), used by children to write state specific to them to
         project files.
     */
-    virtual bool writeXml( QDomNode & layer_node, QDomDocument & document );
+    virtual bool writeXml( QDomNode & layer_node, QDomDocument & document ) const;
 
 
     /** Read custom properties from project file. Added in v1.4
