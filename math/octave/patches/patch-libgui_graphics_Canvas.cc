$NetBSD: patch-libgui_graphics_Canvas.cc,v 1.1 2016/02/16 04:21:40 dbj Exp $

Changes for compiling with Qt5 instead of Qt4

--- libgui/graphics/Canvas.cc.orig	2015-05-23 14:21:53.000000000 +0000
+++ libgui/graphics/Canvas.cc
@@ -527,7 +527,7 @@ Canvas::canvasMousePressEvent (QMouseEve
               QRectF r (bb(0), bb(1), bb(2), bb(3));
 
               r.adjust (-5, -5, 5, 5);
-              if (r.contains (event->posF ()))
+              if (r.contains (event->localPos ()))
                 {
                   currentObj = childObj;
                   break;
@@ -554,7 +554,7 @@ Canvas::canvasMousePressEvent (QMouseEve
                   Matrix bb = it->get_properties ().get_boundingbox (true);
                   QRectF r (bb(0), bb(1), bb(2), bb(3));
 
-                  if (r.contains (event->posF ()))
+                  if (r.contains (event->localPos ()))
                     axesObj = *it;
                 }
 
