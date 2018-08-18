$NetBSD: patch-plugins_wmm_pi_src_MagneticPlotMap.cpp,v 1.1.2.1 2018/08/18 10:31:59 bsiegert Exp $

--- plugins/wmm_pi/src/MagneticPlotMap.cpp.orig	2018-02-07 12:08:26.000000000 +0100
+++ plugins/wmm_pi/src/MagneticPlotMap.cpp	2018-07-02 12:16:38.589797991 +0200
@@ -32,6 +32,7 @@
 #endif //precompiled headers
 
 #include <wx/progdlg.h>
+#include <cmath>
 
 #include "ocpn_plugin.h"
 
@@ -230,7 +231,7 @@
         else
             p = CalcParameter(lonval, rx);
 
-        if(isnan(p)) /* is this actually correct? */
+        if(std::isnan(p)) /* is this actually correct? */
             return true;
 
         if(m_type == DECLINATION && p-ry*m_Spacing < -180) /* way off, try other way around */
@@ -290,7 +291,7 @@
     double p3 = CachedCalcParameter(lat2, lon1);
     double p4 = CachedCalcParameter(lat2, lon2);
 
-    if(isnan(p1) || isnan(p2) || isnan(p3) || isnan(p4))
+    if(std::isnan(p1) || std::isnan(p2) || std::isnan(p3) || std::isnan(p4))
         return;
 
     double ry1, ry2, ry3, ry4 = 0.0;
@@ -318,7 +319,7 @@
     ry1*=m_Spacing, ry2*=m_Spacing, ry3*=m_Spacing, ry4*=m_Spacing;
 
     /* determine which interpolations need line segments */
-    switch(((isnan(lat4)*2 + isnan(lat3))*2 + isnan(lon4))*2 + isnan(lon3)) {
+    switch(((std::isnan(lat4)*2 + std::isnan(lat3))*2 + std::isnan(lon4))*2 + std::isnan(lon3)) {
     case 0: /* all 4 sides? need to recurse to get better resolution */
         lon3 = (lon1+lon2)/2;
         lat3 = (lat1+lat2)/2;
