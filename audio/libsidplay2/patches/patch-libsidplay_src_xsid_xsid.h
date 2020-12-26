$NetBSD: patch-libsidplay_src_xsid_xsid.h,v 1.1 2020/12/26 19:54:14 nat Exp $
Requires unsigned type to avoid overflow.
--- libsidplay/src/xsid/xsid.h.orig	2004-06-14 20:08:02.000000000 +0000
+++ libsidplay/src/xsid/xsid.h
@@ -238,7 +238,7 @@ private:
     uint8_t             sidData0x18;
     bool                _sidSamples;
     int8_t              sampleOffset;
-    static const int8_t sampleConvertTable[16];
+    static const uint8_t sampleConvertTable[16];
     bool                wasRunning;
 
 private:
