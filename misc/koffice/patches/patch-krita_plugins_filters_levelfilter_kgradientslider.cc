$NetBSD: patch-krita_plugins_filters_levelfilter_kgradientslider.cc,v 1.1 2011/12/05 22:52:24 joerg Exp $

--- krita/plugins/filters/levelfilter/kgradientslider.cc.orig	2011-12-05 18:43:40.000000000 +0000
+++ krita/plugins/filters/levelfilter/kgradientslider.cc
@@ -72,7 +72,7 @@ void KGradientSlider::paintEvent(QPaintE
 
         // Draw first gradient
         y = 0;
-        p1.setPen(QPen::QPen(QColor(0,0,0),1, Qt::SolidLine));
+        p1.setPen(QPen(QColor(0,0,0),1, Qt::SolidLine));
         for( x=0; x<255; ++x )
         {
             int gray = (255 * x) / wWidth;
