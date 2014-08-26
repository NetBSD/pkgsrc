$NetBSD: patch-canvas_source_vcl_spritecanvashelper.cxx,v 1.1 2014/08/26 20:58:43 joerg Exp $

--- canvas/source/vcl/spritecanvashelper.cxx.orig	2014-08-24 18:44:02.000000000 +0000
+++ canvas/source/vcl/spritecanvashelper.cxx
@@ -573,12 +573,12 @@ namespace vclcanvas
 
         // repaint all affected sprites on top of background into
         // VDev.
+        ::basegfx::B2DPoint outPos( ::vcl::unotools::b2DPointFromPoint(aOutputPosition) );
         ::std::for_each( rSortedUpdateSprites.begin(),
                          rSortedUpdateSprites.end(),
                          ::boost::bind( &spriteRedrawStub2,
                                         ::boost::ref( maVDev.get() ),
-                                        ::boost::cref(
-                                            ::vcl::unotools::b2DPointFromPoint(aOutputPosition)),
+                                        ::boost::cref( outPos ),
                                         _1 ) );
 
         // flush to screen
