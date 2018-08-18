$NetBSD: patch-src_Alarm.cpp,v 1.1.2.1 2018/08/18 10:31:58 bsiegert Exp $

--- src/Alarm.cpp.orig	2018-03-04 15:24:36.000000000 +0100
+++ src/Alarm.cpp	2018-07-02 12:13:29.929855122 +0200
@@ -27,6 +27,7 @@
 #include <map>
 
 #include <wx/wx.h>
+#include <cmath>
 #include "wx28compat.h"
 #include "wddc.h"
 
@@ -81,7 +82,7 @@
     bool Test() {
         PlugIn_Position_Fix_Ex lastfix = g_watchdog_pi->LastFix();
 
-        if(isnan(lastfix.Lat))
+        if(std::isnan(lastfix.Lat))
             return m_bNoData;
 
         double lat1 = lastfix.Lat, lon1 = lastfix.Lon, lat2, lon2;
@@ -96,7 +97,7 @@
             while(count < 10 && dist1 > 1e-6) {
                 PositionBearingDistanceMercator_Plugin
                     (lastfix.Lat, lastfix.Lon, lastfix.Cog, dist + dist1, &lat2, &lon2);
-                if(!wxIsNaN(lat2) && PlugIn_GSHHS_CrossesLand(lat1, lon1, lat2, lon2)) {
+                if(!std::isnan(lat2) && PlugIn_GSHHS_CrossesLand(lat1, lon1, lat2, lon2)) {
                     if(dist1 < 1) {
                         m_LandFallTime = wxTimeSpan::Seconds(3600.0 * (dist + dist1) / lastfix.Sog);
                         m_crossinglat1 = lat1, m_crossinglon1 = lon1;
@@ -188,7 +189,7 @@
 
     void Render(wdDC &dc, PlugIn_ViewPort &vp) {
         PlugIn_Position_Fix_Ex lastfix = g_watchdog_pi->LastFix();
-        if(isnan(m_crossinglat1))
+        if(std::isnan(m_crossinglat1))
             return;
 
         wxPoint r1, r2, r3, r4;
@@ -350,7 +351,7 @@
     bool Test() {
         PlugIn_Position_Fix_Ex lastfix = g_watchdog_pi->LastFix();
 
-        if(isnan(lastfix.Lat))
+        if(std::isnan(lastfix.Lat))
             return m_bNoData;
 
         double lat, lon;
@@ -389,7 +390,7 @@
         
         switch(m_Mode) {
             case TIME: {
-                if(wxIsNaN(lastfix.Lat) || wxIsNaN(lastfix.Lon) ||wxIsNaN(lastfix.Cog) || wxIsNaN(lastfix.Sog)) break;
+                if(std::isnan(lastfix.Lat) || std::isnan(lastfix.Lon) ||std::isnan(lastfix.Cog) || std::isnan(lastfix.Sog)) break;
                 if(ODVersionNewerThan( 1, 1, 1)) {
                     dist = lastfix.Sog * ( m_TimeMinutes / 60 );
                     PositionBearingDistanceMercator_Plugin(lastfix.Lat, lastfix.Lon, lastfix.Cog, dist, &lat, &lon);
@@ -589,7 +590,7 @@
                 break;
             }
             case DISTANCE: {
-                if(wxIsNaN(lastfix.Lat) || wxIsNaN(lastfix.Lon)) break;
+                if(std::isnan(lastfix.Lat) || std::isnan(lastfix.Lon)) break;
                 // check OD version to see which lookup to use
                 if( ODVersionNewerThan( 1, 1, 1)) {
                     BoundaryCrossingList.clear();
@@ -817,7 +818,7 @@
                 break;
             }
             case ANCHOR: {
-                if(wxIsNaN(lastfix.Lat) || wxIsNaN(lastfix.Lon)) break;
+                if(std::isnan(lastfix.Lat) || std::isnan(lastfix.Lon)) break;
                 if(m_BoundaryName == wxEmptyString)
                     m_BoundaryName = g_BoundaryName;
                 if(m_BoundaryDescription == wxEmptyString)
@@ -850,7 +851,7 @@
                 break;
             }
             case GUARD: {
-                if(wxIsNaN(g_AISTarget.m_dLat) || wxIsNaN(g_AISTarget.m_dLat)) break;
+                if(std::isnan(g_AISTarget.m_dLat) || std::isnan(g_AISTarget.m_dLat)) break;
                 wxJSONValue jMsg;
                 wxJSONWriter writer;
                 wxString    MsgString;
@@ -1701,7 +1702,7 @@
     }
 
     bool Test() {
-        if(isnan(g_watchdog_pi->m_sog))
+        if(std::isnan(g_watchdog_pi->m_sog))
             return m_bNoData;
         return Distance() > m_Radius;
     }
@@ -1718,7 +1719,7 @@
 
         double anchordist = Distance();
         wxString s;
-        if(isnan(anchordist))
+        if(std::isnan(anchordist))
             s = _T("N/A");
         else {
             wxString fmt(_T("%.0f "));
@@ -1782,7 +1783,7 @@
 
 private:
     double Distance() {
-        if(isnan(g_watchdog_pi->m_cog))
+        if(std::isnan(g_watchdog_pi->m_cog))
             return NAN;
         PlugIn_Position_Fix_Ex lastfix = g_watchdog_pi->LastFix();
 
@@ -1820,7 +1821,7 @@
 
     bool Test() {
         double error = CourseError();
-        if(isnan(error))
+        if(std::isnan(error))
             return m_bNoData;
             
         return error > m_Tolerance;
@@ -1829,7 +1830,7 @@
     wxString GetStatus() {
         double courseerror = CourseError();
         wxString s;
-        if(isnan(courseerror))
+        if(std::isnan(courseerror))
             s = _T("N/A");
         else {
             wxString fmt(_T("%.0f "));
@@ -1850,7 +1851,7 @@
         double lat1 = lastfix.Lat, lon1 = lastfix.Lon, lat2, lon2, lat3, lon3;
         double dist = lastfix.Sog;
 
-        if(isnan(dist))
+        if(std::isnan(dist))
             return;
 
         PositionBearingDistanceMercator_Plugin(lat1, lon1, m_Course+m_Tolerance,
@@ -1949,7 +1950,7 @@
 
     wxString GetStatus() {
         wxString s;
-        if(isnan(g_watchdog_pi->m_sog))
+        if(std::isnan(g_watchdog_pi->m_sog))
             s = _T("N/A");
         else {
             wxString fmt(_T("%.1f"));
@@ -1983,7 +1984,7 @@
 
     bool Test() {
         double knots = Knots();
-        if(isnan(knots))
+        if(std::isnan(knots))
             return m_bNoData;
 
         if(m_Mode == UNDERSPEED)
@@ -2038,7 +2039,7 @@
     {
         Alarm::OnTimer( tEvent );
         double sog = g_watchdog_pi->LastFix().Sog;
-        if(!isnan(sog))
+        if(!std::isnan(sog))
             m_SOGqueue.push_front(sog) ;
         return;
     }
@@ -2101,7 +2102,7 @@
                 val = 360 - val;
         }
 
-        if(isnan(val))
+        if(std::isnan(val))
             s = _T("N/A");
         else {
             wxString fmt(_T("%.1f"));
@@ -2300,7 +2301,7 @@
         s += _T(" ");
         
         double val = Value();
-        if(isnan(val))
+        if(std::isnan(val))
             s += _T("N/A");
         else {
             wxString fmt(_T("%.2f"));
@@ -2439,7 +2440,7 @@
                 value = nmea.Mtw.Temperature;
             break;
         }
-        if(isnan(value))
+        if(std::isnan(value))
             return;
 
         m_WeatherDataTime = wxDateTime::Now();
