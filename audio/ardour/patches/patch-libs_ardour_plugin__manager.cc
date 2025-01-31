$NetBSD: patch-libs_ardour_plugin__manager.cc,v 1.2 2025/01/31 22:01:23 wiz Exp $

Fix building without VST3 support.
https://tracker.ardour.org/view.php?id=9886

--- libs/ardour/plugin_manager.cc.orig	2021-08-13 16:20:07.000000000 +0000
+++ libs/ardour/plugin_manager.cc
@@ -116,8 +116,9 @@
 #include <Carbon/Carbon.h>
 #endif
 
-#ifdef VST3_SUPPORT
 #include "ardour/system_exec.h"
+
+#ifdef VST3_SUPPORT
 #include "ardour/vst3_module.h"
 #include "ardour/vst3_plugin.h"
 #include "ardour/vst3_scan.h"
