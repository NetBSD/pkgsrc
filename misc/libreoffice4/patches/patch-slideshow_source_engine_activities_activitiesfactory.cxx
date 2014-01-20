$NetBSD: patch-slideshow_source_engine_activities_activitiesfactory.cxx,v 1.1 2014/01/20 19:27:51 joerg Exp $

--- slideshow/source/engine/activities/activitiesfactory.cxx.orig	2013-10-22 17:49:23.000000000 +0000
+++ slideshow/source/engine/activities/activitiesfactory.cxx
@@ -557,7 +557,7 @@ public:
         // interpolate between nIndex and nIndex+1 values
         (*mpAnim)(
             getPresentationValue(
-                accumulate( maValues.back(),
+                accumulate<ValueType>( maValues.back(),
                             mbCumulative ? nRepeatCount : 0,
                             maInterpolator( maValues[ nIndex ],
                                             maValues[ nIndex+1 ],
@@ -577,7 +577,7 @@ public:
         // this is discrete, thus no lerp here.
         (*mpAnim)(
             getPresentationValue(
-                accumulate( maValues.back(),
+                accumulate<ValueType>( maValues.back(),
                             mbCumulative ? nRepeatCount : 0,
                             maValues[ nFrame ] ) ) );
     }
