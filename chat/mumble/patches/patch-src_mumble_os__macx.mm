$NetBSD: patch-src_mumble_os__macx.mm,v 1.1 2019/06/17 08:08:31 nia Exp $

--- src/mumble/os_macx.mm.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/os_macx.mm
@@ -30,10 +30,12 @@
 */
 
 #include "mumble_pch.hpp"
-#include "Global.h"
 #include "Overlay.h"
 #include "MainWindow.h"
 
+// We define a global macro called 'g'. This can lead to issues when included code uses 'g' as a type or parameter name (like protobuf 3.7 does). As such, for now, we have to make this our last include.
+#include "Global.h"
+
 char *os_lang = NULL;
 static FILE *fConsole = NULL;
 
