$NetBSD: patch-kalzium_src_spectrumwidget.cpp,v 1.1 2014/07/14 09:35:47 jperkin Exp $

Avoid "error: call of overloaded <func> is ambiguous"

--- kalzium/src/spectrumwidget.cpp.orig	2007-05-14 07:38:52.000000000 +0000
+++ kalzium/src/spectrumwidget.cpp
@@ -235,7 +235,7 @@ void SpectrumWidget::drawTickmarks( QPai
 	const int d = 10;
 
 	//the total number of tickmarks to draw (small and long)
-	const int numberOfTickmarks = ( int )floor( width()/d );
+	const int numberOfTickmarks = ( int )floor( (float)width()/d );
 
 	double pos = 0.0;
 		
