$NetBSD: patch-kstars_skyqpainter.cpp,v 1.1 2026/05/09 15:45:26 wiz Exp $

https://bugs.kde.org/show_bug.cgi?id=519958

kstars-3.8.1/kstars/skyqpainter.cpp: In member function 'virtual bool SkyQPainter::drawImageOverlay(const QList<ImageOverlay>*, bool)':
kstars-3.8.1/kstars/skyqpainter.cpp:921:25: error: 'isnan' was not declared in this scope
  921 |         if (!visible || isnan(pos.x()) || isnan(pos.y()))
      |                         ^~~~~

--- kstars/skyqpainter.cpp.orig	2026-05-09 15:33:58.763669163 +0000
+++ kstars/skyqpainter.cpp
@@ -918,7 +918,7 @@ bool SkyQPainter::drawImageOverlay(const QList<ImageOv
 
         bool visible;
         QPointF pos  = m_proj->toScreen(&coord, true, &visible);
-        if (!visible || isnan(pos.x()) || isnan(pos.y()))
+        if (!visible || std::isnan(pos.x()) || std::isnan(pos.y()))
             continue;
 
         const auto PA = (orientation < 0) ? orientation + 360 : orientation;
