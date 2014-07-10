$NetBSD: patch-noatun_modules_voiceprint_voiceprint.cpp,v 1.1 2014/07/10 17:00:21 jperkin Exp $

Avoid ambiguous function call.

--- noatun/modules/voiceprint/voiceprint.cpp.orig	2005-09-10 08:19:35.000000000 +0000
+++ noatun/modules/voiceprint/voiceprint.cpp
@@ -95,7 +95,7 @@ void VoicePrint::scopeEvent(float *data,
 	{
 		float b=data[bands-i-1]+1.0;
 		// the more bands there are, the dimmer each becomes
-		b=log10(b)/log(2) * 16 * brightness;
+		b=log10(b)/log(2.0) * 16 * brightness;
 		int band=int(b);
 		if (band>255) band=255;
 		else if (band<0) band=0;
