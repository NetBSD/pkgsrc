$NetBSD: patch-sunriset.cpp,v 1.1 2019/01/16 14:43:22 martin Exp $

Use fabs() instead of integer abs() for double values.

--- sunriset.cpp.orig	2015-09-20 16:07:55.000000000 +0200
+++ sunriset.cpp	2018-07-19 14:17:06.794662715 +0200
@@ -92,7 +92,7 @@
   /* compute the diurnal arc that the sun traverses to reach the specified altitide altit: */
   double cost = (sind(altitude) - sind(pRun->latitude) * sind(sdec)) / (cosd(pRun->latitude) * cosd(sdec));
 
-  if (abs(cost) < 1.0)
+  if (fabs(cost) < 1.0)
     diurnalArc = 2*acosd(cost)/15.0;    /* Diurnal arc, hours */
   else if (cost>=1.0)
     diurnalArc =  0.0; // Polar Night
