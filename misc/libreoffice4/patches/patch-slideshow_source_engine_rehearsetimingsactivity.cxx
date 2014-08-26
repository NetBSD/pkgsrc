$NetBSD: patch-slideshow_source_engine_rehearsetimingsactivity.cxx,v 1.1 2014/08/26 20:58:43 joerg Exp $

--- slideshow/source/engine/rehearsetimingsactivity.cxx.orig	2014-08-24 19:55:39.000000000 +0000
+++ slideshow/source/engine/rehearsetimingsactivity.cxx
@@ -398,11 +398,12 @@ void RehearseTimingsActivity::viewsChang
     {
         // new sprite pos, transformation might have changed:
         maSpriteRectangle = calcSpriteRectangle( maViews.front().first );
+        ::basegfx::B2DPoint rectMin( maSpriteRectangle.getMinimum() );
 
         // reposition sprites
         for_each_sprite( boost::bind( &cppcanvas::Sprite::move,
                                       _1,
-                                      boost::cref(maSpriteRectangle.getMinimum())) );
+                                      boost::cref( rectMin )) );
 
         // sprites changed, need screen update
         mrScreenUpdater.notifyUpdate();
