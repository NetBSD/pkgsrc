$NetBSD: patch-Main_Source_wsquare.cpp,v 1.1 2014/02/09 17:09:03 wiedi Exp $

fix ambiguous fabs(int) on SunOS
--- Main/Source/wsquare.cpp.orig	2004-12-10 15:51:48.000000000 +0000
+++ Main/Source/wsquare.cpp
@@ -167,7 +167,7 @@ truth wsquare::SignalSeen()
 
 void wsquare::CalculateLuminance()
 {
-  double T = log(1. + fabs(GetWorldMap()->GetAltitude(Pos)) / 500.);
+  double T = log(1. + fabs((double)GetWorldMap()->GetAltitude(Pos)) / 500.);
   int Element = Min((128 - int(37.5 * T)), 255);
   Luminance = MakeRGB24(Element, Element, Element);
 }
