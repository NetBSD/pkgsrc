$NetBSD: patch-src_mumble_AudioOutput.cpp,v 1.1 2018/12/22 18:17:39 nia Exp $

https://github.com/mumble-voip/mumble/pull/3287

--- src/mumble/AudioOutput.cpp.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/AudioOutput.cpp
@@ -431,7 +431,7 @@ bool AudioOutput::mix(void *outbuff, uns
 					top[2] = 0.0f;
 				}
 
-				if (std::abs<float>(front[0] * top[0] + front[1] * top[1] + front[2] * top[2]) > 0.01f) {
+				if (std::abs(front[0] * top[0] + front[1] * top[1] + front[2] * top[2]) > 0.01f) {
 					// Not perpendicular. Assume Y up and rotate 90 degrees.
 
 					float azimuth = 0.0f;
