$NetBSD: patch-src_mumble_OverlayEditorScene.cpp,v 1.1 2019/06/17 08:08:31 nia Exp $

--- src/mumble/OverlayEditorScene.cpp.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/OverlayEditorScene.cpp
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
 OverlayEditorScene::OverlayEditorScene(const OverlaySettings &srcos, QObject *p) : QGraphicsScene(p), os(srcos) {
 	tsColor = Settings::Talking;
 	uiZoom = 2;
