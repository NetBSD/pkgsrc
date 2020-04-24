$NetBSD: patch-src_engine_PADriver.cpp,v 1.1 2020/04/24 08:43:08 nia Exp $

More hostapis (oss, sun)

--- src/engine/PADriver.cpp.orig	2009-03-28 08:48:39.000000000 +0000
+++ src/engine/PADriver.cpp
@@ -142,33 +142,51 @@ int PADriver::setup(bool capture, bool p
 		
 // 		device->message(tr("hostapi name is %1, deviceCount is %2").arg(inf->name).arg(inf->deviceCount), AudioDevice::INFO);
 
-		if (hostapi == "alsa" && inf->type == paALSA) {
-			printf("PADriver:: Found alsa host api, using device %d\n", i);
-			deviceindex = i;
-			break;
-		}
-		
-		if (hostapi == "jack" && inf->type == paJACK) {
-			printf("PADriver:: Found jack host api, using device %d\n", i);
-			deviceindex = i;
-			break;
+		switch (inf->type) {
+			case paALSA:
+				if (hostapi == "alsa") {
+					printf("PADriver:: Found alsa host api, using device %d\n", i);
+					deviceindex = i;
+				}
+				break;
+			case paJACK:
+				if (hostapi == "jack") {
+					printf("PADriver:: Found jack host api, using device %d\n", i);
+					deviceindex = i;
+				}
+				break;
+			case paOSS:
+				if (hostapi == "oss") {
+					printf("PADriver:: Found oss host api, using device %d\n", i);
+					deviceindex = i;
+				}
+				break;
+			case paMME:
+				if (hostapi == "wmme") {
+					printf("PADriver:: Found wmme host api, using device %d\n", i);
+					deviceindex = i;
+				}
+				break;
+			case paDirectSound:
+				if (hostapi == "directsound") {
+					printf("PADriver:: Found directsound host api, using device %d\n", i);
+					deviceindex = i;
+				}
+				break;
+			case paCoreAudio:
+				if (hostapi == "coreaudio") {
+					printf("PADriver:: Found coreaudio host api, using device %d\n", i);
+					deviceindex = i;
+				}
+				break;
+			default:
+				if (hostapi == "sun") {
+					printf("PADriver:: Found sun host api, using device %d\n", i);
+					deviceindex = i;
+				}
+				break;
 		}
-
-		if (hostapi == "wmme" && inf->type == paMME) {
-			printf("PADriver:: Found wmme host api, using device %d\n", i);
-			deviceindex = i;
-			break;
-		}
-		
-		if (hostapi == "directsound" && inf->type == paDirectSound ) {
-			printf("PADriver:: Found directsound host api, using device %d\n", i);
-			deviceindex = i;
-			break;
-		}
-		
-                if (hostapi == "coreaudio" && inf->type == paCoreAudio ) {
-			printf("PADriver:: Found directsound host api, using device %d\n", i);
-			deviceindex = i;
+		if (deviceindex != -1) {
 			break;
 		}
 	}
