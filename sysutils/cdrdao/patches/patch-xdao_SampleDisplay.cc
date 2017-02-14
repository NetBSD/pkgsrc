$NetBSD: patch-xdao_SampleDisplay.cc,v 1.1 2017/02/14 21:22:43 joerg Exp $

--- xdao/SampleDisplay.cc.orig	2017-02-09 17:06:36.365008002 +0000
+++ xdao/SampleDisplay.cc
@@ -768,7 +768,7 @@ bool SampleDisplay::handleLeaveEvent(Gdk
 void SampleDisplay::redraw(gint x, gint y, gint width, gint height,
 			   int drawMask)
 {
-  if (pixmap_ == 0)
+  if (!pixmap_)
     return;
 
   get_window()->draw_drawable(drawGc_, pixmap_, x, y, x, y, width, height);
@@ -820,7 +820,7 @@ void SampleDisplay::updateSamples()
 
   Toc *toc = tocEdit_->toc();
 
-  if (pixmap_ == 0)
+  if (!pixmap_)
     return;
 
   gint halfHeight = chanHeight_ / 2;
@@ -1025,9 +1025,6 @@ void SampleDisplay::updateSamples()
 
 	}
 
-	if (&pixmap_ == 0)
-	  std::cout << "null !!" << std::endl;
-
 	if (0 && (gint)di < sampleEndX_) {
 	  pos = sampleBuf[len -1].left() * halfHeight;
 	  pos /= SHRT_MAX;
@@ -1084,7 +1081,7 @@ void SampleDisplay::updateSamples()
 
 void SampleDisplay::drawCursor(gint x)
 {
-  if (pixmap_ == 0)
+  if (!pixmap_)
     return;
 
   if (x < sampleStartX_ || x > sampleEndX_)
@@ -1118,7 +1115,7 @@ void SampleDisplay::drawTimeTick(gint x,
 {
   char buf[50];
 
-  if (pixmap_ == 0)
+  if (!pixmap_)
     return;
 
   unsigned long min = sample / (60 * 44100);
