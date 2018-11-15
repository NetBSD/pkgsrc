$NetBSD: patch-xdao_SampleDisplay.cc,v 1.2 2018/11/15 01:13:02 markd Exp $

--- gcdmaster/SampleDisplay.cc.orig	2017-02-09 17:06:36.365008002 +0000
+++ gcdmaster/SampleDisplay.cc
@@ -1025,9 +1025,6 @@ void SampleDisplay::updateSamples()
 
 	}
 
-	if (&pixmap_ == 0)
-	  std::cout << "null !!" << std::endl;
-
 	if (0 && (gint)di < sampleEndX_) {
 	  pos = sampleBuf[len -1].left() * halfHeight;
 	  pos /= SHRT_MAX;
