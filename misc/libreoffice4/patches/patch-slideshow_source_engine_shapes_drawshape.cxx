$NetBSD: patch-slideshow_source_engine_shapes_drawshape.cxx,v 1.1 2014/08/26 20:58:43 joerg Exp $

--- slideshow/source/engine/shapes/drawshape.cxx.orig	2014-08-24 20:46:29.000000000 +0000
+++ slideshow/source/engine/shapes/drawshape.cxx
@@ -168,6 +168,7 @@ namespace slideshow
             }
 
             // redraw all view shapes, by calling their update() method
+            ViewShape::RenderArgs renderArgs( getViewRenderArgs() );
             if( ::std::count_if( maViewShapes.begin(),
                                  maViewShapes.end(),
                                  ::boost::bind<bool>(
@@ -178,8 +179,7 @@ namespace slideshow
                                                                              // the extra mem_fn. WTF.
                                      _1,
                                      ::boost::cref( mpCurrMtf ),
-                                     ::boost::cref(
-                                         getViewRenderArgs() ),
+                                     ::boost::cref( renderArgs ),
                                      nUpdateFlags,
                                      isVisible() ) )
                 != static_cast<ViewShapeVector::difference_type>(maViewShapes.size()) )
