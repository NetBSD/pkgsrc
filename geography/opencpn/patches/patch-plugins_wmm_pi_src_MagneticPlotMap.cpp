$NetBSD: patch-plugins_wmm_pi_src_MagneticPlotMap.cpp,v 1.1 2018/04/09 18:44:50 bouyer Exp $

--- plugins/wmm_pi/src/MagneticPlotMap.cpp.orig	2018-04-09 18:01:32.900360435 +0200
+++ plugins/wmm_pi/src/MagneticPlotMap.cpp	2018-04-09 18:02:29.319040318 +0200
@@ -230,7 +230,7 @@
         else
             p = CalcParameter(lonval, rx);
 
-        if(isnan(p)) /* is this actually correct? */
+        if(std::isnan(p)) /* is this actually correct? */
             return true;
 
         if(m_type == DECLINATION && p-ry*m_Spacing < -180) /* way off, try other way around */
@@ -290,7 +290,7 @@
     double p3 = CachedCalcParameter(lat2, lon1);
     double p4 = CachedCalcParameter(lat2, lon2);
 
-    if(isnan(p1) || isnan(p2) || isnan(p3) || isnan(p4))
+    if(std::isnan(p1) || std::isnan(p2) || std::isnan(p3) || std::isnan(p4))
         return;
 
     double ry1, ry2, ry3, ry4 = 0.0;
@@ -318,7 +318,7 @@
     ry1*=m_Spacing, ry2*=m_Spacing, ry3*=m_Spacing, ry4*=m_Spacing;
 
     /* determine which interpolations need line segments */
-    switch(((isnan(lat4)*2 + isnan(lat3))*2 + isnan(lon4))*2 + isnan(lon3)) {
+    switch(((std::isnan(lat4)*2 + std::isnan(lat3))*2 + std::isnan(lon4))*2 + std::isnan(lon3)) {
     case 0: /* all 4 sides? need to recurse to get better resolution */
         lon3 = (lon1+lon2)/2;
         lat3 = (lat1+lat2)/2;
