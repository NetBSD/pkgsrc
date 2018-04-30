$NetBSD: patch-src_spreadsheet_sheet.cpp,v 1.1 2018/04/30 04:39:41 ryoon Exp $

* Fix build with boost 1.65.0

--- src/spreadsheet/sheet.cpp.orig	2017-11-15 23:12:57.000000000 +0000
+++ src/spreadsheet/sheet.cpp
@@ -387,7 +387,7 @@ void sheet::set_date_time(row_t row, col
 
     double days_since_epoch = (d - origin).days();
 
-    double ms = second * 1000000.0;
+    long ms = second * 1000000.0;
 
     posix_time::time_duration t(
         posix_time::hours(hour) +
@@ -726,12 +726,12 @@ date_time_t sheet::get_date_time(row_t r
 
     long hours = 0;
     long minutes = 0;
-    double seconds = 0.0;
+    long seconds = 0.0;
 
     if (time_fraction)
     {
         // Convert a fraction day to microseconds.
-        double ms = time_fraction * 24.0 * 60.0 * 60.0 * 1000000.0;
+        long ms = time_fraction * 24.0 * 60.0 * 60.0 * 1000000.0;
         posix_time::time_duration td = posix_time::microsec(ms);
 
         hours = td.hours();
