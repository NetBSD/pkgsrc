$NetBSD: patch-krita_ui_kcurve.cc,v 1.1 2011/12/05 22:52:24 joerg Exp $

--- krita/ui/kcurve.cc.orig	2011-12-05 18:33:50.000000000 +0000
+++ krita/ui/kcurve.cc
@@ -146,7 +146,7 @@ void KCurve::paintEvent(QPaintEvent *)
         pm.fill();
     
     // Draw grid separators.
-    p1.setPen(QPen::QPen(Qt::gray, 1, Qt::SolidLine));
+    p1.setPen(QPen(Qt::gray, 1, Qt::SolidLine));
     p1.drawLine(wWidth/3, 0, wWidth/3, wHeight);                 
     p1.drawLine(2*wWidth/3, 0, 2*wWidth/3, wHeight);                 
     p1.drawLine(0, wHeight/3, wWidth, wHeight/3);                 
@@ -154,7 +154,7 @@ void KCurve::paintEvent(QPaintEvent *)
 
     // Draw curve.
     double curvePrevVal = getCurveValue(0.0);
-    p1.setPen(QPen::QPen(Qt::black, 1, Qt::SolidLine));    
+    p1.setPen(QPen(Qt::black, 1, Qt::SolidLine));    
     for (x = 0 ; x < wWidth ; x++)
     {
         double curveX;
@@ -184,13 +184,13 @@ void KCurve::paintEvent(QPaintEvent *)
         
             if(p == m_grab_point)
             {
-                p1.setPen(QPen::QPen(Qt::red, 3, Qt::SolidLine));
+                p1.setPen(QPen(Qt::red, 3, Qt::SolidLine));
                 p1.drawEllipse( int(curveX * wWidth) - 2, 
                     wHeight - 2 - int(curveY * wHeight), 4, 4 ); 
             }
             else
             {
-                p1.setPen(QPen::QPen(Qt::red, 1, Qt::SolidLine));
+                p1.setPen(QPen(Qt::red, 1, Qt::SolidLine));
             
                 p1.drawEllipse( int(curveX * wWidth) - 3, 
                     wHeight - 3 - int(curveY * wHeight), 6, 6 ); 
