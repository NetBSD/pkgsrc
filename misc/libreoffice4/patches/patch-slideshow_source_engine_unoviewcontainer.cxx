$NetBSD: patch-slideshow_source_engine_unoviewcontainer.cxx,v 1.1 2014/08/26 20:58:43 joerg Exp $

--- slideshow/source/engine/unoviewcontainer.cxx.orig	2014-08-24 20:59:43.000000000 +0000
+++ slideshow/source/engine/unoviewcontainer.cxx
@@ -45,11 +45,12 @@ namespace slideshow
             const UnoViewVector::iterator aEnd( maViews.end() );
 
             // already added?
+            uno::Reference<presentation::XSlideShowView> xView (rView->getUnoView());
             if( ::std::find_if( maViews.begin(),
                                 aEnd,
                                 ::boost::bind(
                                     ::std::equal_to< uno::Reference< presentation::XSlideShowView > >(),
-                                    ::boost::cref( rView->getUnoView() ),
+                                    ::boost::cref( xView ),
                                     ::boost::bind(
                                         &UnoView::getUnoView,
                                         _1 ) ) ) != aEnd )
