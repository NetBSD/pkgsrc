$NetBSD: patch-src_qtMonitorProfiler_qtmonitorprofilerdialog.cpp,v 1.1 2014/08/21 16:37:51 jperkin Exp $

Fix "error: call of overloaded 'floor(int)' is ambiguous".

--- src/qtMonitorProfiler/qtmonitorprofilerdialog.cpp.orig	2005-08-22 03:36:58.000000000 +0000
+++ src/qtMonitorProfiler/qtmonitorprofilerdialog.cpp
@@ -271,8 +271,8 @@ void qtMonitorProfilerDialog::ValuesToCo
 
 void qtMonitorProfilerDialog::SlidersToValues()
 {
-	sys.hdr.device.La = floor(LaScroll -> value() / 10);
-	sys.hdr.device.Yb = floor(YbScroll -> value() / 10);
+	sys.hdr.device.La = floor((float)LaScroll -> value() / 10);
+	sys.hdr.device.Yb = floor((float)YbScroll -> value() / 10);
 
 }
 
