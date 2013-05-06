$NetBSD: patch-gpsdump.cc,v 1.1 2013/05/06 14:56:35 joerg Exp $

--- gpsdump.cc.orig	2013-05-06 07:12:44.000000000 +0000
+++ gpsdump.cc
@@ -108,7 +108,7 @@ int GPSDump::DumpTrack(GPSD *in_gps) {
 
     int sig = 0, qual = 0, noise = 0;
 
-    if (time(0) - last_info.ts.tv_sec < decay && last_info.quality != -1) {
+    if (time(0) - last_info.ts.tv_sec < ::decay && last_info.quality != -1) {
         sig = last_info.signal;
         qual = last_info.quality;
         noise = last_info.noise;
