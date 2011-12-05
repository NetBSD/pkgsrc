$NetBSD: patch-krita_plugins_filters_colorsfilters_kis__perchannel__filter.cc,v 1.1 2011/12/05 22:52:24 joerg Exp $

--- krita/plugins/filters/colorsfilters/kis_perchannel_filter.cc.orig	2011-12-05 18:42:12.000000000 +0000
+++ krita/plugins/filters/colorsfilters/kis_perchannel_filter.cc
@@ -273,7 +273,7 @@ void KisPerChannelConfigWidget::setActiv
     QPixmap pix(256, height);
     pix.fill();
     QPainter p(&pix);
-    p.setPen(QPen::QPen(Qt::gray,1, Qt::SolidLine));
+    p.setPen(QPen(Qt::gray,1, Qt::SolidLine));
 
     m_histogram->setChannel(ch);
 
@@ -331,7 +331,7 @@ KisPerChannelConfigWidget::KisPerChannel
     // Create the horizontal gradient label
     QPixmap hgradientpix(256, 1);
     QPainter hgp(&hgradientpix);
-    hgp.setPen(QPen::QPen(QColor(0,0,0),1, Qt::SolidLine));
+    hgp.setPen(QPen(QColor(0,0,0),1, Qt::SolidLine));
     for( i=0; i<256; ++i )
     {
         hgp.setPen(QColor(i,i,i));
@@ -342,7 +342,7 @@ KisPerChannelConfigWidget::KisPerChannel
     // Create the vertical gradient label
     QPixmap vgradientpix(1, 256);
     QPainter vgp(&vgradientpix);
-    vgp.setPen(QPen::QPen(QColor(0,0,0),1, Qt::SolidLine));
+    vgp.setPen(QPen(QColor(0,0,0),1, Qt::SolidLine));
     for( i=0; i<256; ++i )
     {
         vgp.setPen(QColor(i,i,i));
