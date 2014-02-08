$NetBSD: patch-umbrello_widgets_floatingdashlinewidget.cpp,v 1.1 2014/02/08 12:53:32 wiedi Exp $

--- umbrello/widgets/floatingdashlinewidget.cpp.orig	2014-01-02 19:37:28.000000000 +0000
+++ umbrello/widgets/floatingdashlinewidget.cpp
@@ -86,7 +86,7 @@ void FloatingDashLineWidget::setText(con
 bool FloatingDashLineWidget::onLine(const UMLScenePoint &point)
 {
     // check if the given point is the start or end point of the line
-    if (( (abs( y() + height() - point.y() )) <= POINT_DELTA) || (abs( y() - point.y() ) <= POINT_DELTA)) {
+    if (( (abs( (long) (y() + height() - point.y()) )) <= POINT_DELTA) || (abs( (long) (y() - point.y()) ) <= POINT_DELTA)) {
         return true;
     }
     // check if the given point is the start or end point of the line
