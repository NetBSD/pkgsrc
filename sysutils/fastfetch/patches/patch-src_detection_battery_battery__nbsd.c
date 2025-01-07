$NetBSD: patch-src_detection_battery_battery__nbsd.c,v 1.1 2025/01/07 21:01:16 vins Exp $

Fix battery percentage detection.

--- src/detection/battery/battery_nbsd.c.orig	2025-01-07 20:49:32.957096242 +0000
+++ src/detection/battery/battery_nbsd.c
@@ -88,7 +88,7 @@ const char* ffDetectBattery(FF_MAYBE_UNU
             ffStrbufInit(&battery->manufactureDate);
             battery->timeRemaining = -1;
 
-            battery->capacity = (double) curr / max;
+            battery->capacity = ((double)curr / (double)max) * 100.0;
             if (charging)
                 ffStrbufAppendS(&battery->status, "Charging, ");
             else if (dischargeRate)
