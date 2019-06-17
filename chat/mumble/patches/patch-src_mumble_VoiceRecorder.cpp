$NetBSD: patch-src_mumble_VoiceRecorder.cpp,v 1.1 2019/06/17 08:08:31 nia Exp $

--- src/mumble/VoiceRecorder.cpp.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/VoiceRecorder.cpp
@@ -36,11 +36,13 @@
 
 #include "AudioOutput.h"
 #include "ClientUser.h"
-#include "Global.h"
 #include "ServerHandler.h"
 
 #include "../Timer.h"
 
+// We define a global macro called 'g'. This can lead to issues when included code uses 'g' as a type or parameter name (like protobuf 3.7 does). As such, for now, we have to make this our last include.
+#include "Global.h"
+
 VoiceRecorder::RecordBuffer::RecordBuffer(const ClientUser *cu,
         boost::shared_array<float> buffer, int samples, quint64 timestamp) :
 		cuUser(cu), fBuffer(buffer), iSamples(samples), uiTimestamp(timestamp) {
