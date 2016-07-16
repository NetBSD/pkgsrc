$NetBSD: patch-umbrello_widgets_associationline.cpp,v 1.1 2016/07/16 03:36:51 markd Exp $

make gcc6 happy

--- umbrello/widgets/associationline.cpp.orig	2014-11-04 06:47:37.000000000 +0000
+++ umbrello/widgets/associationline.cpp
@@ -859,8 +859,8 @@ QPainterPath AssociationLine::createOrth
     if (points.size() > 1) {
         QPointF start  = points.first();
         QPointF end    = points.last();
-        qreal deltaX = abs(start.x() - end.x());
-        qreal deltaY = abs(start.y() - end.y());
+        qreal deltaX = std::abs(start.x() - end.x());
+        qreal deltaY = std::abs(start.y() - end.y());
         // DEBUG("AssociationLine") << "start=" << start << " / end=" << end
         //               << " / deltaX=" << deltaX << " / deltaY=" << deltaY;
         QVector<QPointF> vector;
