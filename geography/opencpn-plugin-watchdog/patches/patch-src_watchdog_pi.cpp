$NetBSD: patch-src_watchdog_pi.cpp,v 1.3 2018/08/27 15:59:07 bouyer Exp $

--- src/watchdog_pi.cpp.orig	2018-08-25 23:08:44.000000000 +0200
+++ src/watchdog_pi.cpp	2018-08-27 15:58:48.263716962 +0200
@@ -26,6 +26,7 @@
 
 #include <wx/wx.h>
 #include <wx/stdpaths.h>
+#include <cmath>
 
 #include "json/json.h"
 
@@ -343,14 +344,14 @@
 {
     /* calculate course and speed over ground from gps */
     double dt = m_lastfix.FixTime - m_lasttimerfix.FixTime;
-    if(!isnan(m_lastfix.Lat) && !isnan(m_lasttimerfix.Lat) && dt > 0) {
+    if(!std::isnan(m_lastfix.Lat) && !std::isnan(m_lasttimerfix.Lat) && dt > 0) {
         /* this way helps avoid surge speed from gps from surfing waves etc... */
         double cog, sog;
         DistanceBearingMercator_Plugin(m_lastfix.Lat, m_lastfix.Lon,
                                        m_lasttimerfix.Lat, m_lasttimerfix.Lon, &cog, &sog);
         sog *= (3600.0 / dt);
 
-        if(isnan(m_cog))
+        if(std::isnan(m_cog))
             m_cog = cog, m_sog = sog;
         else {
             cog = heading_resolve(cog, m_cog);
