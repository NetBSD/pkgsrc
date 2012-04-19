$NetBSD: patch-plugins_video_H.263-1998_h263pframe.cxx,v 1.1 2012/04/19 12:44:07 hans Exp $

--- plugins/video/H.263-1998/h263pframe.cxx.orig	2009-09-22 02:57:52.000000000 +0200
+++ plugins/video/H.263-1998/h263pframe.cxx	2012-04-18 21:11:57.720726385 +0200
@@ -325,7 +325,7 @@ uint32_t H263PFrame::parseHeader(uint8_t
   bool PB  = false;
   bool CPM = false;
   bool PEI = false;
-  bool SS  = false;
+  bool SS_ = false;
   bool RPS = false;
   bool PCF = false;
   bool UMV = false;
@@ -351,9 +351,9 @@ uint32_t H263PFrame::parseHeader(uint8_t
                              << " AP: "  << headerBits.GetBits(1) 
                              << " AIC: " << headerBits.GetBits(1)
                              << " DF: "  << headerBits.GetBits(1));
-      SS = headerBits.GetBits(1);
+      SS_ = headerBits.GetBits(1);
       RPS = headerBits.GetBits(1);
-      TRACE_UP(4, "H263+\tHeader\tSS: "  << SS
+      TRACE_UP(4, "H263+\tHeader\tSS: "  << SS_
                           << " RPS: " << RPS
                           << " ISD: " << headerBits.GetBits(1)
                           << " AIV: " << headerBits.GetBits(1)
@@ -414,7 +414,7 @@ uint32_t H263PFrame::parseHeader(uint8_t
           else
            TRACE_UP(4, "H263+\tHeader\tUUI: 0" << headerBits.GetBits(1));
       }
-      if (SS) {
+      if (SS_) {
         TRACE_UP(4, "H263+\tHeader\tSSS:" << headerBits.GetBits(2));
       }
     }
