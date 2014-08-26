$NetBSD: patch-slideshow_source_engine_activities_activitybase.hxx,v 1.1 2014/08/26 20:58:43 joerg Exp $

--- slideshow/source/engine/activities/activitybase.hxx.orig	2014-08-24 19:11:37.000000000 +0000
+++ slideshow/source/engine/activities/activitybase.hxx
@@ -111,7 +111,7 @@ protected:
     ShapeAttributeLayerSharedPtr getShapeAttributeLayer() const
         { return mpAttributeLayer; }
 
-    bool isRepeatCountValid() const { return maRepeats; }
+    bool isRepeatCountValid() const { return bool(maRepeats); }
     double getRepeatCount() const { return *maRepeats; }
     bool isAutoReverse() const { return mbAutoReverse; }
 
