$NetBSD: patch-src_mumble_BanEditor.cpp,v 1.1 2019/06/17 08:08:31 nia Exp $

--- src/mumble/BanEditor.cpp.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/BanEditor.cpp
@@ -33,10 +33,12 @@
 #include "BanEditor.h"
 
 #include "Channel.h"
-#include "Global.h"
 #include "Net.h"
 #include "ServerHandler.h"
 
+// We define a global macro called 'g'. This can lead to issues when included code uses 'g' as a type or parameter name (like protobuf 3.7 does). As such, for now, we have to make this our last include.
+#include "Global.h"
+
 BanEditor::BanEditor(const MumbleProto::BanList &msg, QWidget *p) : QDialog(p) {
 	setupUi(this);
 
