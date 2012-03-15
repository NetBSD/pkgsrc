$NetBSD: patch-dom_plugins_ipc_PluginModuleChild.h,v 1.1.1.1 2012/03/15 08:58:28 ryoon Exp $

--- dom/plugins/ipc/PluginModuleChild.h.orig	2012-03-09 22:20:12.000000000 +0000
+++ dom/plugins/ipc/PluginModuleChild.h
@@ -358,7 +358,7 @@ private:
 
     // we get this from the plugin
     NP_PLUGINSHUTDOWN mShutdownFunc;
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_BSD)
     NP_PLUGINUNIXINIT mInitializeFunc;
 #elif defined(OS_WIN) || defined(OS_MACOSX)
     NP_PLUGININIT mInitializeFunc;
