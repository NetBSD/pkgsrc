$NetBSD: patch-src_mumble_Log.cpp,v 1.1 2019/06/17 08:08:31 nia Exp $

--- src/mumble/Log.cpp.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/Log.cpp
@@ -36,13 +36,15 @@
 #include "AudioOutput.h"
 #include "AudioOutputSample.h"
 #include "Channel.h"
-#include "Global.h"
 #include "MainWindow.h"
 #include "NetworkConfig.h"
 #include "RichTextEditor.h"
 #include "ServerHandler.h"
 #include "TextToSpeech.h"
 
+// We define a global macro called 'g'. This can lead to issues when included code uses 'g' as a type or parameter name (like protobuf 3.7 does). As such, for now, we have to make this our last include.
+#include "Global.h"
+
 static ConfigWidget *LogConfigDialogNew(Settings &st) {
 	return new LogConfig(st);
 }
