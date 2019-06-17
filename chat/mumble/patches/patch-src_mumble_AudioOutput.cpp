$NetBSD: patch-src_mumble_AudioOutput.cpp,v 1.2 2019/06/17 08:08:31 nia Exp $

https://github.com/mumble-voip/mumble/pull/3287

--- src/mumble/AudioOutput.cpp.orig	2019-06-17 07:42:51.973326995 +0000
+++ src/mumble/AudioOutput.cpp
@@ -37,13 +37,15 @@
 #include "AudioOutputSample.h"
 #include "AudioOutputSpeech.h"
 #include "User.h"
-#include "Global.h"
 #include "Message.h"
 #include "Plugins.h"
 #include "PacketDataStream.h"
 #include "ServerHandler.h"
 #include "VoiceRecorder.h"
 
+// We define a global macro called 'g'. This can lead to issues when included code uses 'g' as a type or parameter name (like protobuf 3.7 does). As such, for now, we have to make this our last include.
+#include "Global.h"
+
 // Remember that we cannot use static member classes that are not pointers, as the constructor
 // for AudioOutputRegistrar() might be called before they are initialized, as the constructor
 // is called from global initialization.
@@ -431,7 +433,7 @@ bool AudioOutput::mix(void *outbuff, uns
 					top[2] = 0.0f;
 				}
 
-				if (std::abs<float>(front[0] * top[0] + front[1] * top[1] + front[2] * top[2]) > 0.01f) {
+				if (std::abs(front[0] * top[0] + front[1] * top[1] + front[2] * top[2]) > 0.01f) {
 					// Not perpendicular. Assume Y up and rotate 90 degrees.
 
 					float azimuth = 0.0f;
