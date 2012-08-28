$NetBSD: patch-dom_plugins_ipc_PluginModuleChild.h,v 1.3 2012/08/28 23:27:10 ryoon Exp $

--- dom/plugins/ipc/PluginModuleChild.h.orig	2012-08-24 22:55:28.000000000 +0000
+++ dom/plugins/ipc/PluginModuleChild.h
@@ -330,7 +330,7 @@ private:
 
     // we get this from the plugin
     NP_PLUGINSHUTDOWN mShutdownFunc;
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_BSD)
     NP_PLUGINUNIXINIT mInitializeFunc;
 #elif defined(OS_WIN) || defined(OS_MACOSX)
     NP_PLUGININIT mInitializeFunc;
