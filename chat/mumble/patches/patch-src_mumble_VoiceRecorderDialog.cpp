$NetBSD: patch-src_mumble_VoiceRecorderDialog.cpp,v 1.1 2019/06/17 08:08:31 nia Exp $

--- src/mumble/VoiceRecorderDialog.cpp.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/VoiceRecorderDialog.cpp
@@ -34,10 +34,12 @@
 #include "VoiceRecorderDialog.h"
 
 #include "AudioOutput.h"
-#include "Global.h"
 #include "ServerHandler.h"
 #include "VoiceRecorder.h"
 
+// We define a global macro called 'g'. This can lead to issues when included code uses 'g' as a type or parameter name (like protobuf 3.7 does). As such, for now, we have to make this our last include.
+#include "Global.h"
+
 VoiceRecorderDialog::VoiceRecorderDialog(QWidget *p) : QDialog(p), qtTimer(new QTimer(this)) {
 	qtTimer->setObjectName(QLatin1String("qtTimer"));
 	qtTimer->setInterval(200);
