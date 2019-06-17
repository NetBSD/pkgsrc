$NetBSD: patch-src_mumble_Plugins.cpp,v 1.1 2019/06/17 08:08:31 nia Exp $

--- src/mumble/Plugins.cpp.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/Plugins.cpp
@@ -32,7 +32,6 @@
 
 #include "Plugins.h"
 
-#include "Global.h"
 #include "Log.h"
 #include "MainWindow.h"
 #include "Message.h"
@@ -40,6 +39,9 @@
 #include "../../plugins/mumble_plugin.h"
 #include "WebFetch.h"
 
+// We define a global macro called 'g'. This can lead to issues when included code uses 'g' as a type or parameter name (like protobuf 3.7 does). As such, for now, we have to make this our last include.
+#include "Global.h"
+
 static ConfigWidget *PluginConfigDialogNew(Settings &st) {
 	return new PluginConfig(st);
 }
