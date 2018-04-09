$NetBSD: patch-src_Alarm.cpp,v 1.1 2018/04/09 14:18:26 bouyer Exp $

--- src/Alarm.cpp.orig	2018-04-09 14:38:56.349739590 +0200
+++ src/Alarm.cpp	2018-04-09 14:39:24.526834514 +0200
@@ -81,7 +81,7 @@
     bool Test() {
         PlugIn_Position_Fix_Ex lastfix = g_watchdog_pi->LastFix();
 
-        if(isnan(lastfix.Lat))
+        if(std::isnan(lastfix.Lat))
             return m_bNoData;
 
         double lat1 = lastfix.Lat, lon1 = lastfix.Lon, lat2, lon2;
@@ -188,7 +188,7 @@
 
     void Render(wdDC &dc, PlugIn_ViewPort &vp) {
         PlugIn_Position_Fix_Ex lastfix = g_watchdog_pi->LastFix();
-        if(isnan(m_crossinglat1))
+        if(std::isnan(m_crossinglat1))
             return;
 
         wxPoint r1, r2, r3, r4;
@@ -350,7 +350,7 @@
     bool Test() {
         PlugIn_Position_Fix_Ex lastfix = g_watchdog_pi->LastFix();
 
-        if(isnan(lastfix.Lat))
+        if(std::isnan(lastfix.Lat))
             return m_bNoData;
 
         double lat, lon;
@@ -1701,7 +1701,7 @@
     }
 
     bool Test() {
-        if(isnan(g_watchdog_pi->m_sog))
+        if(std::isnan(g_watchdog_pi->m_sog))
             return m_bNoData;
         return Distance() > m_Radius;
     }
@@ -1718,7 +1718,7 @@
 
         double anchordist = Distance();
         wxString s;
-        if(isnan(anchordist))
+        if(std::isnan(anchordist))
             s = _T("N/A");
         else {
             wxString fmt(_T("%.0f "));
@@ -1782,7 +1782,7 @@
 
 private:
     double Distance() {
-        if(isnan(g_watchdog_pi->m_cog))
+        if(std::isnan(g_watchdog_pi->m_cog))
             return NAN;
         PlugIn_Position_Fix_Ex lastfix = g_watchdog_pi->LastFix();
 
@@ -1820,7 +1820,7 @@
 
     bool Test() {
         double error = CourseError();
-        if(isnan(error))
+        if(std::isnan(error))
             return m_bNoData;
             
         return error > m_Tolerance;
@@ -1829,7 +1829,7 @@
     wxString GetStatus() {
         double courseerror = CourseError();
         wxString s;
-        if(isnan(courseerror))
+        if(std::isnan(courseerror))
             s = _T("N/A");
         else {
             wxString fmt(_T("%.0f "));
@@ -1850,7 +1850,7 @@
         double lat1 = lastfix.Lat, lon1 = lastfix.Lon, lat2, lon2, lat3, lon3;
         double dist = lastfix.Sog;
 
-        if(isnan(dist))
+        if(std::isnan(dist))
             return;
 
         PositionBearingDistanceMercator_Plugin(lat1, lon1, m_Course+m_Tolerance,
@@ -1949,7 +1949,7 @@
 
     wxString GetStatus() {
         wxString s;
-        if(isnan(g_watchdog_pi->m_sog))
+        if(std::isnan(g_watchdog_pi->m_sog))
             s = _T("N/A");
         else {
             wxString fmt(_T("%.1f"));
@@ -1983,7 +1983,7 @@
 
     bool Test() {
         double knots = Knots();
-        if(isnan(knots))
+        if(std::isnan(knots))
             return m_bNoData;
 
         if(m_Mode == UNDERSPEED)
@@ -2038,7 +2038,7 @@
     {
         Alarm::OnTimer( tEvent );
         double sog = g_watchdog_pi->LastFix().Sog;
-        if(!isnan(sog))
+        if(!std::isnan(sog))
             m_SOGqueue.push_front(sog) ;
         return;
     }
@@ -2101,7 +2101,7 @@
                 val = 360 - val;
         }
 
-        if(isnan(val))
+        if(std::isnan(val))
             s = _T("N/A");
         else {
             wxString fmt(_T("%.1f"));
@@ -2300,7 +2300,7 @@
         s += _T(" ");
         
         double val = Value();
-        if(isnan(val))
+        if(std::isnan(val))
             s += _T("N/A");
         else {
             wxString fmt(_T("%.2f"));
@@ -2439,7 +2439,7 @@
                 value = nmea.Mtw.Temperature;
             break;
         }
-        if(isnan(value))
+        if(std::isnan(value))
             return;
 
         m_WeatherDataTime = wxDateTime::Now();
