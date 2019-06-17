$NetBSD: patch-src_mumble_VersionCheck.cpp,v 1.1 2019/06/17 08:08:31 nia Exp $

--- src/mumble/VersionCheck.cpp.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/VersionCheck.cpp
@@ -32,10 +32,12 @@
 
 #include "VersionCheck.h"
 
-#include "Global.h"
 #include "MainWindow.h"
 #include "WebFetch.h"
 
+// We define a global macro called 'g'. This can lead to issues when included code uses 'g' as a type or parameter name (like protobuf 3.7 does). As such, for now, we have to make this our last include.
+#include "Global.h"
+
 VersionCheck::VersionCheck(bool autocheck, QObject *p, bool focus) : QObject(p) {
 	bSilent = autocheck;
 
