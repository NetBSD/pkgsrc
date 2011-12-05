$NetBSD: patch-krita_plugins_filters_colorsfilters_kis__brightness__contrast__filter.cc,v 1.1 2011/12/05 22:52:24 joerg Exp $

--- krita/plugins/filters/colorsfilters/kis_brightness_contrast_filter.cc.orig	2011-12-05 18:43:21.000000000 +0000
+++ krita/plugins/filters/colorsfilters/kis_brightness_contrast_filter.cc
@@ -276,7 +276,7 @@ KisBrightnessContrastConfigWidget::KisBr
     // Create the horizontal gradient label
     QPixmap hgradientpix(256, 1);
     QPainter hgp(&hgradientpix);
-    hgp.setPen(QPen::QPen(QColor(0,0,0),1, Qt::SolidLine));
+    hgp.setPen(QPen(QColor(0,0,0),1, Qt::SolidLine));
     for( i=0; i<256; ++i )
     {
         hgp.setPen(QColor(i,i,i));
@@ -287,7 +287,7 @@ KisBrightnessContrastConfigWidget::KisBr
     // Create the vertical gradient label
     QPixmap vgradientpix(1, 256);
     QPainter vgp(&vgradientpix);
-    vgp.setPen(QPen::QPen(QColor(0,0,0),1, Qt::SolidLine));
+    vgp.setPen(QPen(QColor(0,0,0),1, Qt::SolidLine));
     for( i=0; i<256; ++i )
     {
         vgp.setPen(QColor(i,i,i));
@@ -300,7 +300,7 @@ KisBrightnessContrastConfigWidget::KisBr
     QPixmap pix(256, height);
     pix.fill();
     QPainter p(&pix);
-    p.setPen(QPen::QPen(Qt::gray,1, Qt::SolidLine));
+    p.setPen(QPen(Qt::gray,1, Qt::SolidLine));
 
     double highest = (double)histogram.calculations().getHighest();
     Q_INT32 bins = histogram.producer()->numberOfBins();
