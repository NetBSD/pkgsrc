$NetBSD: patch-src_Alarm.cpp,v 1.3 2018/08/27 15:59:07 bouyer Exp $

--- src/Alarm.cpp.orig	2018-08-25 23:08:44.000000000 +0200
+++ src/Alarm.cpp	2018-08-27 16:00:48.979962717 +0200
@@ -27,6 +27,7 @@
 #include <map>
 
 #include <wx/wx.h>
+#include <cmath>
 #include "wddc.h"
 
 #include <wx/process.h>
@@ -70,7 +71,7 @@
     wxString Type() { return _("Anchor"); }
 
     bool Test() {
-        if(isnan(g_watchdog_pi->m_sog))
+        if(std::isnan(g_watchdog_pi->m_sog))
             return m_bNoData;
         return Distance() > m_Radius;
     }
@@ -87,7 +88,7 @@
 
         double anchordist = Distance();
         wxString s;
-        if(isnan(anchordist))
+        if(std::isnan(anchordist))
             s = "N/A";
         else {
             wxString fmt("%.0f ");
@@ -106,6 +107,7 @@
                        m_Radius/1853.0/60.0,
                        m_Longitude);
         
+        dc.SetBrush(*wxTRANSPARENT_BRUSH);
         if(m_bEnabled) {
             if(m_bFired)
                 dc.SetPen(wxPen(*wxRED, 2));
@@ -151,7 +152,7 @@
 
 private:
     double Distance() {
-        if(isnan(g_watchdog_pi->m_cog))
+        if(std::isnan(g_watchdog_pi->m_cog))
             return NAN;
         PlugIn_Position_Fix_Ex lastfix = g_watchdog_pi->LastFix();
 
@@ -180,7 +181,7 @@
 
     bool Test() {
         double error = CourseError();
-        if(isnan(error))
+        if(std::isnan(error))
             return m_bNoData;
             
         return error > m_Tolerance;
@@ -189,7 +190,7 @@
     wxString GetStatus() {
         double courseerror = CourseError();
         wxString s;
-        if(isnan(courseerror))
+        if(std::isnan(courseerror))
             s = "N/A";
         else {
             wxString fmt("%.0f ");
@@ -210,7 +211,7 @@
         double lat1 = lastfix.Lat, lon1 = lastfix.Lon, lat2, lon2, lat3, lon3;
         double dist = lastfix.Sog;
 
-        if(isnan(dist))
+        if(std::isnan(dist))
             return;
 
         PositionBearingDistanceMercator_Plugin(lat1, lon1, m_Course+m_Tolerance,
@@ -301,7 +302,7 @@
 
     wxString GetStatus() {
         wxString s;
-        if(isnan(g_watchdog_pi->m_sog))
+        if(std::isnan(g_watchdog_pi->m_sog))
             s = "N/A";
         else {
             wxString fmt("%.1f");
@@ -335,7 +336,7 @@
 
     bool Test() {
         double knots = Knots();
-        if(isnan(knots))
+        if(std::isnan(knots))
             return m_bNoData;
 
         if(m_Mode == UNDERSPEED)
@@ -390,7 +391,7 @@
     {
         Alarm::OnTimer( tEvent );
         double sog = g_watchdog_pi->LastFix().Sog;
-        if(!isnan(sog))
+        if(!std::isnan(sog))
             m_SOGqueue.push_front(sog);
         while((int)m_SOGqueue.size() > m_iAverageTime)
             m_SOGqueue.pop_back();
@@ -452,12 +453,12 @@
         switch(m_Mode) {
         case UNDERSPEED:
         case OVERSPEED:
-            if(isnan(m_speed))
+            if(std::isnan(m_speed))
                 return "N/A";
             else
                 return wxString::Format(fmt + (m_Mode == UNDERSPEED ? " < " : " > ") + fmt, m_speed, m_dVal);
         case DIRECTION:
-            if(isnan(m_direction))
+            if(std::isnan(m_direction))
                 return "N/A";
             else
                 return wxString::Format(fmt + " < " + fmt + " < " + fmt,
@@ -470,7 +471,7 @@
     void Render(wdDC &dc, PlugIn_ViewPort &vp) {
         if(m_Mode != DIRECTION)
             return;
-        if(isnan(m_direction))
+        if(std::isnan(m_direction))
             return;
         PlugIn_Position_Fix_Ex lastfix = g_watchdog_pi->LastFix();
 
@@ -644,7 +645,7 @@
         s += " ";
         
         double val = Value();
-        if(isnan(val))
+        if(std::isnan(val))
             s += "N/A";
         else {
             wxString fmt("%.2f");
@@ -783,7 +784,7 @@
                 value = nmea.Mtw.Temperature;
             break;
         }
-        if(isnan(value))
+        if(std::isnan(value))
             return;
 
         m_WeatherDataTime = wxDateTime::Now();
@@ -965,7 +966,7 @@
     bool Test() {
         PlugIn_Position_Fix_Ex lastfix = g_watchdog_pi->LastFix();
 
-        if(isnan(lastfix.Lat))
+        if(std::isnan(lastfix.Lat))
             return m_bNoData;
 
         double lat1 = lastfix.Lat, lon1 = lastfix.Lon, lat2, lon2;
@@ -980,7 +981,7 @@
             while(count < 10 && dist1 > 1e-6) {
                 PositionBearingDistanceMercator_Plugin
                     (lastfix.Lat, lastfix.Lon, lastfix.Cog, dist + dist1, &lat2, &lon2);
-                if(!wxIsNaN(lat2) && PlugIn_GSHHS_CrossesLand(lat1, lon1, lat2, lon2)) {
+                if(!std::isnan(lat2) && PlugIn_GSHHS_CrossesLand(lat1, lon1, lat2, lon2)) {
                     if(dist1 < 1) {
                         m_LandFallTime = wxTimeSpan::Seconds(3600.0 * (dist + dist1) / lastfix.Sog);
                         m_crossinglat1 = lat1, m_crossinglon1 = lon1;
@@ -1072,7 +1073,7 @@
 
     void Render(wdDC &dc, PlugIn_ViewPort &vp) {
         PlugIn_Position_Fix_Ex lastfix = g_watchdog_pi->LastFix();
-        if(isnan(m_crossinglat1))
+        if(std::isnan(m_crossinglat1))
             return;
 
         wxPoint r1, r2, r3, r4;
@@ -1234,7 +1235,7 @@
     bool Test() {
         PlugIn_Position_Fix_Ex lastfix = g_watchdog_pi->LastFix();
 
-        if(isnan(lastfix.Lat))
+        if(std::isnan(lastfix.Lat))
             return m_bNoData;
 
         double lat, lon;
@@ -1273,7 +1274,7 @@
         
         switch(m_Mode) {
             case TIME: {
-                if(wxIsNaN(lastfix.Lat) || wxIsNaN(lastfix.Lon) ||wxIsNaN(lastfix.Cog) || wxIsNaN(lastfix.Sog)) break;
+                if(std::isnan(lastfix.Lat) || std::isnan(lastfix.Lon) ||std::isnan(lastfix.Cog) || std::isnan(lastfix.Sog)) break;
                 if(ODVersionNewerThan( 1, 1, 1)) {
                     dist = lastfix.Sog * ( m_TimeMinutes / 60 );
                     PositionBearingDistanceMercator_Plugin(lastfix.Lat, lastfix.Lon, lastfix.Cog, dist, &lat, &lon);
@@ -1472,7 +1473,7 @@
                 break;
             }
             case DISTANCE: {
-                if(wxIsNaN(lastfix.Lat) || wxIsNaN(lastfix.Lon)) break;
+                if(std::isnan(lastfix.Lat) || std::isnan(lastfix.Lon)) break;
                 // check OD version to see which lookup to use
                 if( ODVersionNewerThan( 1, 1, 1)) {
                     BoundaryCrossingList.clear();
@@ -1700,7 +1701,7 @@
                 break;
             }
             case ANCHOR: {
-                if(wxIsNaN(lastfix.Lat) || wxIsNaN(lastfix.Lon)) break;
+                if(std::isnan(lastfix.Lat) || std::isnan(lastfix.Lon)) break;
                 if(m_BoundaryName == wxEmptyString)
                     m_BoundaryName = g_BoundaryName;
                 if(m_BoundaryDescription == wxEmptyString)
@@ -1731,7 +1732,7 @@
                 break;
             }
             case GUARD: {
-                if(wxIsNaN(g_AISTarget.m_dLat) || wxIsNaN(g_AISTarget.m_dLat)) break;
+                if(std::isnan(g_AISTarget.m_dLat) || std::isnan(g_AISTarget.m_dLat)) break;
                 Json::Value jMsg;
                 Json::FastWriter writer;
                 jMsg["Source"] = "WATCHDOG_PI";
--- Alarm.cpp.orig	2018-08-27 16:54:18.043496648 +0200
+++ Alarm.cpp	2018-08-27 16:54:21.910702531 +0200
