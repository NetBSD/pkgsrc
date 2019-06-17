$NetBSD: patch-src_mumble_Tokens.cpp,v 1.1 2019/06/17 08:08:31 nia Exp $

--- src/mumble/Tokens.cpp.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/Tokens.cpp
@@ -33,9 +33,11 @@
 #include "Tokens.h"
 
 #include "Database.h"
-#include "Global.h"
 #include "ServerHandler.h"
 
+// We define a global macro called 'g'. This can lead to issues when included code uses 'g' as a type or parameter name (like protobuf 3.7 does). As such, for now, we have to make this our last include.
+#include "Global.h"
+
 Tokens::Tokens(QWidget *p) : QDialog(p) {
 	setupUi(this);
 
