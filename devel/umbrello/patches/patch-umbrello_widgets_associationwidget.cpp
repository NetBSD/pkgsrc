$NetBSD: patch-umbrello_widgets_associationwidget.cpp,v 1.1 2014/02/08 12:53:32 wiedi Exp $

--- umbrello/widgets/associationwidget.cpp.orig	2014-01-02 19:37:28.000000000 +0000
+++ umbrello/widgets/associationwidget.cpp
@@ -2561,7 +2561,7 @@ void AssociationWidget::constrainTextPos
     const int y0 = p0.y();
     const int x1 = p1.x();
     const int y1 = p1.y();
-    double r = sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0)) / 2;
+    double r = sqrt((double) ((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0))) / 2;
     if (textWidth > r)
         r = textWidth;
     // swap textCenter{X,Y} to convert from Qt coord.system.
