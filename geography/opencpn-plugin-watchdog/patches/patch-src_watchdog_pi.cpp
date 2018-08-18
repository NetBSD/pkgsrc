$NetBSD: patch-src_watchdog_pi.cpp,v 1.1.2.1 2018/08/18 10:31:58 bsiegert Exp $

--- src/watchdog_pi.cpp.orig	2018-03-04 15:24:36.000000000 +0100
+++ src/watchdog_pi.cpp	2018-07-02 12:05:36.112240381 +0200
@@ -26,6 +26,7 @@
 
 #include <wx/wx.h>
 #include <wx/stdpaths.h>
+#include <cmath>
 
 #include "wxJSON/jsonreader.h"
 #include "wxJSON/jsonwriter.h"
@@ -345,14 +346,14 @@
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
             m_cog = .25*cog + .75*m_cog;
