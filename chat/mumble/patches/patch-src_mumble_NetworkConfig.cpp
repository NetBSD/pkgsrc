$NetBSD: patch-src_mumble_NetworkConfig.cpp,v 1.1 2019/06/17 08:08:31 nia Exp $

--- src/mumble/NetworkConfig.cpp.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/NetworkConfig.cpp
@@ -34,10 +34,12 @@
 
 #include "NetworkConfig.h"
 
-#include "Global.h"
 #include "MainWindow.h"
 #include "OSInfo.h"
 
+// We define a global macro called 'g'. This can lead to issues when included code uses 'g' as a type or parameter name (like protobuf 3.7 does). As such, for now, we have to make this our last include.
+#include "Global.h"
+
 static ConfigWidget *NetworkConfigNew(Settings &st) {
 	return new NetworkConfig(st);
 }
