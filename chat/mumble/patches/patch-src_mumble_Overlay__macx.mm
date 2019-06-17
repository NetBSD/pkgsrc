$NetBSD: patch-src_mumble_Overlay__macx.mm,v 1.1 2019/06/17 08:08:31 nia Exp $

--- src/mumble/Overlay_macx.mm.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/Overlay_macx.mm
@@ -33,9 +33,11 @@
 #import <ScriptingBridge/ScriptingBridge.h>
 #include <Carbon/Carbon.h>
 #include "Overlay.h"
-#include "Global.h"
 #include "MainWindow.h"
 
+// We define a global macro called 'g'. This can lead to issues when included code uses 'g' as a type or parameter name (like protobuf 3.7 does). As such, for now, we have to make this our last include.
+#include "Global.h"
+
 extern "C" {
 #include <xar/xar.h>
 }
