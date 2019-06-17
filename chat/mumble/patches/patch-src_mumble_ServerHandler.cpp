$NetBSD: patch-src_mumble_ServerHandler.cpp,v 1.1 2019/06/17 08:08:31 nia Exp $

--- src/mumble/ServerHandler.cpp.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/ServerHandler.cpp
@@ -37,7 +37,6 @@
 #include "Cert.h"
 #include "Connection.h"
 #include "Database.h"
-#include "Global.h"
 #include "MainWindow.h"
 #include "Message.h"
 #include "NetworkConfig.h"
@@ -47,6 +46,9 @@
 #include "SSL.h"
 #include "User.h"
 
+// We define a global macro called 'g'. This can lead to issues when included code uses 'g' as a type or parameter name (like protobuf 3.7 does). As such, for now, we have to make this our last include.
+#include "Global.h"
+
 ServerHandlerMessageEvent::ServerHandlerMessageEvent(const QByteArray &msg, unsigned int mtype, bool flush) : QEvent(static_cast<QEvent::Type>(SERVERSEND_EVENT)) {
 	qbaMsg = msg;
 	uiType = mtype;
