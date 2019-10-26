$NetBSD: patch-src_common_pa__stream.c,v 1.1 2019/10/26 17:22:39 nia Exp $

Add features needed to make portmixer work in audacity.

--- src/common/pa_stream.c.orig	2016-10-30 01:23:04.000000000 +0000
+++ src/common/pa_stream.c
@@ -93,6 +93,8 @@ void PaUtil_InitializeStreamRepresentati
     streamRepresentation->streamInfo.inputLatency = 0.;
     streamRepresentation->streamInfo.outputLatency = 0.;
     streamRepresentation->streamInfo.sampleRate = 0.;
+
+    streamRepresentation->hostApiType = 0;
 }
 
 
