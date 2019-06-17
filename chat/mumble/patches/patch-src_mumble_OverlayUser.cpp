$NetBSD: patch-src_mumble_OverlayUser.cpp,v 1.1 2019/06/17 08:08:31 nia Exp $

--- src/mumble/OverlayUser.cpp.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/OverlayUser.cpp
@@ -35,7 +35,6 @@
 #include "User.h"
 #include "Channel.h"
 #include "ClientUser.h"
-#include "Global.h"
 #include "Message.h"
 #include "Database.h"
 #include "NetworkConfig.h"
@@ -43,6 +42,9 @@
 #include "MainWindow.h"
 #include "GlobalShortcut.h"
 
+// We define a global macro called 'g'. This can lead to issues when included code uses 'g' as a type or parameter name (like protobuf 3.7 does). As such, for now, we have to make this our last include.
+#include "Global.h"
+
 OverlayUser::OverlayUser(ClientUser *cu, unsigned int height, OverlaySettings *osptr) : OverlayGroup(), os(osptr), uiSize(height), cuUser(cu), tsColor(Settings::Passive) {
 	setup();
 	updateLayout();
