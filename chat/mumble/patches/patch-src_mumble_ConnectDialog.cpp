$NetBSD: patch-src_mumble_ConnectDialog.cpp,v 1.1 2019/06/17 08:08:31 nia Exp $

--- src/mumble/ConnectDialog.cpp.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/ConnectDialog.cpp
@@ -40,10 +40,12 @@
 
 #include "Channel.h"
 #include "Database.h"
-#include "Global.h"
 #include "ServerHandler.h"
 #include "WebFetch.h"
 
+// We define a global macro called 'g'. This can lead to issues when included code uses 'g' as a type or parameter name (like protobuf 3.7 does). As such, for now, we have to make this our last include.
+#include "Global.h"
+
 QMap<QString, QIcon> ServerItem::qmIcons;
 QList<PublicInfo> ConnectDialog::qlPublicServers;
 QString ConnectDialog::qsUserCountry, ConnectDialog::qsUserCountryCode, ConnectDialog::qsUserContinentCode;
