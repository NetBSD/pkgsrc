$NetBSD: patch-src_mumble_CustomElements.cpp,v 1.1 2019/06/17 08:08:31 nia Exp $

--- src/mumble/CustomElements.cpp.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/CustomElements.cpp
@@ -34,10 +34,11 @@
 #include "CustomElements.h"
 
 #include "ClientUser.h"
-#include "Global.h"
 #include "MainWindow.h"
 #include "Log.h"
 
+// We define a global macro called 'g'. This can lead to issues when included code uses 'g' as a type or parameter name (like protobuf 3.7 does). As such, for now, we have to make this our last include.
+#include "Global.h"
 
 LogTextBrowser::LogTextBrowser(QWidget *p)
 	: m_pos(0)
