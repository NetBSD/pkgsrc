$NetBSD: patch-src_mumble_MainWindow.cpp,v 1.1 2019/06/17 08:08:31 nia Exp $

--- src/mumble/MainWindow.cpp.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/MainWindow.cpp
@@ -46,7 +46,6 @@
 #include "Connection.h"
 #include "ConnectDialog.h"
 #include "Database.h"
-#include "Global.h"
 #include "GlobalShortcut.h"
 #include "Log.h"
 #include "Net.h"
@@ -75,6 +74,9 @@
 #include "ConfigDialog_macx.h"
 #endif
 
+// We define a global macro called 'g'. This can lead to issues when included code uses 'g' as a type or parameter name (like protobuf 3.7 does). As such, for now, we have to make this our last include.
+#include "Global.h"
+
 /*!
   \fn void MainWindow::findDesiredChannel()
   This function tries to join a desired channel on connect. It gets called
