$NetBSD: patch-src_mumble_Log__unix.cpp,v 1.1 2019/06/17 08:08:31 nia Exp $

--- src/mumble/Log_unix.cpp.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/Log_unix.cpp
@@ -32,10 +32,12 @@
 #include "mumble_pch.hpp"
 
 #include "Log.h"
-#include "Global.h"
 #include "MainWindow.h"
 #include "Settings.h"
 
+// We define a global macro called 'g'. This can lead to issues when included code uses 'g' as a type or parameter name (like protobuf 3.7 does). As such, for now, we have to make this our last include.
+#include "Global.h"
+
 void Log::postNotification(MsgType mt, const QString &console, const QString &plain) {
 	// Message notification with balloon tooltips
 	QString qsIcon;
