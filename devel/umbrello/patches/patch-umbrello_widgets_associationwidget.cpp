$NetBSD: patch-umbrello_widgets_associationwidget.cpp,v 1.3 2016/07/16 03:36:51 markd Exp $

make gcc6 happy

--- umbrello/widgets/associationwidget.cpp.orig	2014-11-04 06:47:37.000000000 +0000
+++ umbrello/widgets/associationwidget.cpp
@@ -2118,9 +2118,9 @@ void AssociationWidget::updatePointsExce
     p1.setX(xmil + (xfin - xmil)*1/2); p1.setY(ymil + (yfin - ymil)*1/3);
     p2.setX(xmil - (xmil - xdeb)*1/2); p2.setY(ymil - (ymil - ydeb)*1/3);
 
-    if (abs(p1.x() - p2.x()) <= 10)
+    if (std::abs(p1.x() - p2.x()) <= 10)
         ESPACEX = 15;
-    if (abs(p1.y() - p2.y()) <= 10)
+    if (std::abs(p1.y() - p2.y()) <= 10)
         ESPACEY = 15;
 
     m_associationLine->setEndPoints(QPointF(xdeb, ydeb), QPointF(xfin, yfin));
@@ -2688,8 +2688,8 @@ void AssociationWidget::constrainTextPos
         r = textWidth;
     // swap textCenter{X,Y} to convert from Qt coord.system.
     const QPointF origTextCenter(textCenterY, textCenterX);
-    const int relX = abs(origTextCenter.x() - midP.x());
-    const int relY = abs(origTextCenter.y() - midP.y());
+    const int relX = std::abs(origTextCenter.x() - midP.x());
+    const int relY = std::abs(origTextCenter.y() - midP.y());
     const double negativeWhenInsideCircle = relX * relX + relY * relY - r * r;
     if (negativeWhenInsideCircle <= 0.0) {
         return;
