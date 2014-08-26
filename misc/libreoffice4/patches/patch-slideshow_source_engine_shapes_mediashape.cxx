$NetBSD: patch-slideshow_source_engine_shapes_mediashape.cxx,v 1.1 2014/08/26 20:58:43 joerg Exp $

--- slideshow/source/engine/shapes/mediashape.cxx.orig	2014-08-24 20:55:41.000000000 +0000
+++ slideshow/source/engine/shapes/mediashape.cxx
@@ -125,12 +125,13 @@ namespace slideshow
         void MediaShape::implViewsChanged()
         {
             // resize all ViewShapes
+            ::basegfx::B2DRectangle bounds( getBounds() );
             ::std::for_each( maViewMediaShapes.begin(),
                              maViewMediaShapes.end(),
                              ::boost::bind(
                                  &ViewMediaShape::resize,
                                  _1,
-                                 ::boost::cref( getBounds())) );
+                                 ::boost::cref( bounds )) );
         }
 
         // ---------------------------------------------------------------------
