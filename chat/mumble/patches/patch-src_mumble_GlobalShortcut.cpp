$NetBSD: patch-src_mumble_GlobalShortcut.cpp,v 1.1 2019/06/17 08:08:31 nia Exp $

--- src/mumble/GlobalShortcut.cpp.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/GlobalShortcut.cpp
@@ -36,9 +36,11 @@
 #include "ClientUser.h"
 #include "Channel.h"
 #include "Database.h"
-#include "Global.h"
 #include "MainWindow.h"
 
+// We define a global macro called 'g'. This can lead to issues when included code uses 'g' as a type or parameter name (like protobuf 3.7 does). As such, for now, we have to make this our last include.
+#include "Global.h"
+
 /*!
   \class ShortcutKeyWidget
   Widget used to define and key combination for a shortcut. Once it gains
