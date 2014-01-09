$NetBSD: patch-kpdf_ui_presentationwidget.cpp,v 1.1 2014/01/09 20:11:27 jperkin Exp $

Avoid ambiguous function call.

--- kpdf/ui/presentationwidget.cpp.orig	2008-02-13 09:37:05.000000000 +0000
+++ kpdf/ui/presentationwidget.cpp
@@ -436,7 +436,7 @@ void PresentationWidget::overlayClick( c
         return;
 
     // compute angle relative to indicator (note coord transformation)
-    float angle = 0.5 + 0.5 * atan2( -xPos, -yPos ) / M_PI;
+    float angle = 0.5 + 0.5 * atan2((double)-xPos, (double)-yPos) / M_PI;
     int pageIndex = (int)( angle * ( m_frames.count() - 1 ) + 0.5 );
 
     // go to selected page
