$NetBSD: patch-src_mumble_LCD.cpp,v 1.1 2019/06/17 08:08:31 nia Exp $

--- src/mumble/LCD.cpp.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/LCD.cpp
@@ -35,10 +35,12 @@
 
 #include "ClientUser.h"
 #include "Channel.h"
-#include "Global.h"
 #include "Message.h"
 #include "ServerHandler.h"
 
+// We define a global macro called 'g'. This can lead to issues when included code uses 'g' as a type or parameter name (like protobuf 3.7 does). As such, for now, we have to make this our last include.
+#include "Global.h"
+
 QList<LCDEngineNew> *LCDEngineRegistrar::qlInitializers;
 
 LCDEngineRegistrar::LCDEngineRegistrar(LCDEngineNew cons) {
