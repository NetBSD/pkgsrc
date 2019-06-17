$NetBSD: patch-src_mumble_Overlay.cpp,v 1.1 2019/06/17 08:08:31 nia Exp $

--- src/mumble/Overlay.cpp.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/Overlay.cpp
@@ -35,7 +35,6 @@
 #include "Channel.h"
 #include "ClientUser.h"
 #include "Database.h"
-#include "Global.h"
 #include "GlobalShortcut.h"
 #include "MainWindow.h"
 #include "Message.h"
@@ -45,6 +44,9 @@
 #include "User.h"
 #include "WebFetch.h"
 
+// We define a global macro called 'g'. This can lead to issues when included code uses 'g' as a type or parameter name (like protobuf 3.7 does). As such, for now, we have to make this our last include.
+#include "Global.h"
+
 OverlayAppInfo::OverlayAppInfo(QString name, QIcon icon) {
 	qsDisplayName = name;
 	qiIcon = icon;
