$NetBSD: patch-umbrello_umbrello_associationwidget.cpp,v 1.1 2014/09/24 14:33:28 jperkin Exp $

Avoid "error: call of overloaded <func> is ambiguous".

--- umbrello/umbrello/associationwidget.cpp.orig	2007-10-08 09:49:29.000000000 +0000
+++ umbrello/umbrello/associationwidget.cpp
@@ -1713,7 +1713,7 @@ float AssociationWidget::perpendicularPr
         sx = (b2 - b1) / (slope1 - slope2);
         sy = slope1*sx + b1;
     }
-    distance = (int)( sqrt( ((x3 - sx)*(x3 - sx)) + ((y3 - sy)*(y3 - sy)) ) );
+    distance = (int)( sqrt((double) ((x3 - sx)*(x3 - sx)) + ((y3 - sy)*(y3 - sy)) ) );
 
     ResultingPoint.setX( (int)sy );
     ResultingPoint.setY( (int)sx );
@@ -1893,7 +1893,7 @@ void AssociationWidget::constrainTextPos
     const int y0 = p0.y();
     const int x1 = p1.x();
     const int y1 = p1.y();
-    double r = sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0)) / 2;
+    double r = sqrt((double)(x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0)) / 2;
     if (textWidth > r)
         r = textWidth;
     // swap textCenter{X,Y} to convert from Qt coord.system.
