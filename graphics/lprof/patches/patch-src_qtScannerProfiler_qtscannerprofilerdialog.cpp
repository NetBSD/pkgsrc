$NetBSD: patch-src_qtScannerProfiler_qtscannerprofilerdialog.cpp,v 1.1 2014/08/21 16:37:51 jperkin Exp $

Fix "error: call of overloaded 'floor(int)' is ambiguous".

--- src/qtScannerProfiler/qtscannerprofilerdialog.cpp.orig	2005-08-20 01:11:41.000000000 +0000
+++ src/qtScannerProfiler/qtscannerprofilerdialog.cpp
@@ -179,8 +179,8 @@ void qtScannerProfilerDialog::ValuesToCo
 
 void qtScannerProfilerDialog::SlidersToValues()
 {
-    sys.hdr.device.La = floor(LaScroll -> value() / 10);
-    sys.hdr.device.Yb = floor(YbScroll -> value() / 10);
+    sys.hdr.device.La = floor((float)LaScroll -> value() / 10);
+    sys.hdr.device.Yb = floor((float)YbScroll -> value() / 10);
 
 }
 
