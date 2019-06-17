$NetBSD: patch-src_mumble_DBus.cpp,v 1.1 2019/06/17 08:08:31 nia Exp $

--- src/mumble/DBus.cpp.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/DBus.cpp
@@ -34,10 +34,11 @@
 
 #include "Channel.h"
 #include "ClientUser.h"
-#include "Global.h"
 #include "MainWindow.h"
 #include "ServerHandler.h"
 
+// We define a global macro called 'g'. This can lead to issues when included code uses 'g' as a type or parameter name (like protobuf 3.7 does). As such, for now, we have to make this our last include.
+#include "Global.h"
 
 MumbleDBus::MumbleDBus(QObject *mw) : QDBusAbstractAdaptor(mw) {
 }
