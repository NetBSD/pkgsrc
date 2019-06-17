$NetBSD: patch-src_mumble_Messages.cpp,v 1.1 2019/06/17 08:08:31 nia Exp $

--- src/mumble/Messages.cpp.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/Messages.cpp
@@ -41,7 +41,6 @@
 #include "Connection.h"
 #include "ConnectDialog.h"
 #include "Database.h"
-#include "Global.h"
 #include "GlobalShortcut.h"
 #include "Log.h"
 #include "MainWindow.h"
@@ -55,6 +54,9 @@
 #include "VersionCheck.h"
 #include "ViewCert.h"
 
+// We define a global macro called 'g'. This can lead to issues when included code uses 'g' as a type or parameter name (like protobuf 3.7 does). As such, for now, we have to make this our last include.
+#include "Global.h"
+
 #define ACTOR_INIT \
 	ClientUser *pSrc=NULL; \
 	if (msg.has_actor()) \
