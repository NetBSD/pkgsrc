$NetBSD: patch-dom_plugins_ipc_PluginModuleChild.h,v 1.1 2012/03/06 12:34:09 ryoon Exp $

--- dom/plugins/ipc/PluginModuleChild.h.orig	2011-12-20 23:28:14.000000000 +0000
+++ dom/plugins/ipc/PluginModuleChild.h
@@ -340,7 +340,7 @@ private:
 
     // we get this from the plugin
     NP_PLUGINSHUTDOWN mShutdownFunc;
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_BSD)
     NP_PLUGINUNIXINIT mInitializeFunc;
 #elif defined(OS_WIN) || defined(OS_MACOSX)
     NP_PLUGININIT mInitializeFunc;
