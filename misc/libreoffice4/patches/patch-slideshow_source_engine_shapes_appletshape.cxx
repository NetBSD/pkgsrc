$NetBSD: patch-slideshow_source_engine_shapes_appletshape.cxx,v 1.1 2014/08/26 20:58:43 joerg Exp $

--- slideshow/source/engine/shapes/appletshape.cxx.orig	2014-08-24 20:31:18.000000000 +0000
+++ slideshow/source/engine/shapes/appletshape.cxx
@@ -148,12 +148,13 @@ namespace slideshow
         void AppletShape::implViewsChanged()
         {
             // resize all ViewShapes
+            ::basegfx::B2DRectangle bounds( AppletShape::getBounds() );
             ::std::for_each( maViewAppletShapes.begin(),
                              maViewAppletShapes.end(),
                              ::boost::bind(
                                  &ViewAppletShape::resize,
                                  _1,
-                                 ::boost::cref( AppletShape::getBounds())) );
+                                 ::boost::cref( bounds )) );
         }
 
         // ---------------------------------------------------------------------
@@ -252,11 +253,12 @@ namespace slideshow
 
         bool AppletShape::implStartIntrinsicAnimation()
         {
+            ::basegfx::B2DRectangle bounds( getBounds() );
             ::std::for_each( maViewAppletShapes.begin(),
                              maViewAppletShapes.end(),
                              ::boost::bind( &ViewAppletShape::startApplet,
                                             _1,
-                                            ::boost::cref( getBounds() )));
+                                            ::boost::cref( bounds )));
             mbIsPlaying = true;
 
             return true;
