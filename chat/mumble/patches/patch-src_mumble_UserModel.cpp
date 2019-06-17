$NetBSD: patch-src_mumble_UserModel.cpp,v 1.1 2019/06/17 08:08:31 nia Exp $

--- src/mumble/UserModel.cpp.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/UserModel.cpp
@@ -36,7 +36,6 @@
 #include "ClientUser.h"
 #include "Channel.h"
 #include "Database.h"
-#include "Global.h"
 #include "LCD.h"
 #include "Log.h"
 #include "MainWindow.h"
@@ -46,6 +45,9 @@
 #include "Usage.h"
 #include "User.h"
 
+// We define a global macro called 'g'. This can lead to issues when included code uses 'g' as a type or parameter name (like protobuf 3.7 does). As such, for now, we have to make this our last include.
+#include "Global.h"
+
 QHash <Channel *, ModelItem *> ModelItem::c_qhChannels;
 QHash <ClientUser *, ModelItem *> ModelItem::c_qhUsers;
 bool ModelItem::bUsersTop = false;
