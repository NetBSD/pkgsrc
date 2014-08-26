$NetBSD: patch-canvas_source_cairo_cairo__spritecanvashelper.cxx,v 1.1 2014/08/26 20:58:43 joerg Exp $

--- canvas/source/cairo/cairo_spritecanvashelper.cxx.orig	2014-08-24 18:35:48.000000000 +0000
+++ canvas/source/cairo/cairo_spritecanvashelper.cxx
@@ -402,11 +402,12 @@ namespace cairocanvas
         ::basegfx::computeSetDifference( aUncoveredAreas,
                                          rUpdateArea.maTotalBounds,
                                          ::basegfx::B2DRange( rDestRect ) );
+        SurfaceSharedPtr surface(mpOwningSpriteCanvas->getBufferSurface());
         ::std::for_each( aUncoveredAreas.begin(),
                          aUncoveredAreas.end(),
                          ::boost::bind( &repaintBackground,
                                         boost::cref(pCompositingCairo),
-                                        boost::cref(mpOwningSpriteCanvas->getBufferSurface()),
+                                        boost::cref(surface),
                                         _1 ) );
 
         cairo_rectangle( pWindowCairo.get(), 0, 0, rSize.getX(), rSize.getY() );
