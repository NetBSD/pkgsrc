$NetBSD: patch-kmoon_kmoonwidget.cpp,v 1.1 2013/09/12 20:50:54 jperkin Exp $

Avoid "error: call of overloaded <func> is ambiguous".

--- kmoon/kmoonwidget.cpp.orig	2005-10-10 14:58:36.000000000 +0000
+++ kmoon/kmoonwidget.cpp
@@ -285,7 +285,7 @@ void MoonWidget::renderGraphic()
 
   if (QPixmap::defaultDepth() > 8) {
 
-    if (fabs(_angle)!=0) { // nothing to rotate
+    if (fabs((float)_angle)!=0) { // nothing to rotate
       //We expand the image 2x before rotating, rotate it, and then average out
       //the pixel for better quality
       int dmw = 2 * mw;
