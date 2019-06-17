$NetBSD: patch-src_mumble_OverlayConfig.cpp,v 1.1 2019/06/17 08:08:31 nia Exp $

--- src/mumble/OverlayConfig.cpp.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/OverlayConfig.cpp
@@ -34,7 +34,6 @@
 #include "OverlayText.h"
 #include "User.h"
 #include "Channel.h"
-#include "Global.h"
 #include "Message.h"
 #include "Database.h"
 #include "NetworkConfig.h"
@@ -42,6 +41,9 @@
 #include "MainWindow.h"
 #include "GlobalShortcut.h"
 
+// We define a global macro called 'g'. This can lead to issues when included code uses 'g' as a type or parameter name (like protobuf 3.7 does). As such, for now, we have to make this our last include.
+#include "Global.h"
+
 static ConfigWidget *OverlayConfigDialogNew(Settings &st) {
 	return new OverlayConfig(st);
 }
@@ -481,6 +483,8 @@ void OverlayConfig::on_qpbLoadPreset_cli
 	load_preset.load(&qs);
 	qs.endGroup();
 
+#include "Global.h"
+
 #ifdef Q_OS_WIN
 	load_preset.qslBlacklist = s.os.qslBlacklist;
 	load_preset.qslWhitelist = s.os.qslWhitelist;
