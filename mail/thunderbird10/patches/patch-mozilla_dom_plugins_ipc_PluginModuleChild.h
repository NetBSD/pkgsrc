$NetBSD: patch-mozilla_dom_plugins_ipc_PluginModuleChild.h,v 1.1.1.1 2012/03/15 09:45:29 ryoon Exp $

--- mozilla/dom/plugins/ipc/PluginModuleChild.h.orig	2012-02-16 10:24:53.000000000 +0000
+++ mozilla/dom/plugins/ipc/PluginModuleChild.h
@@ -358,7 +358,7 @@ private:
 
     // we get this from the plugin
     NP_PLUGINSHUTDOWN mShutdownFunc;
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_BSD)
     NP_PLUGINUNIXINIT mInitializeFunc;
 #elif defined(OS_WIN) || defined(OS_MACOSX)
     NP_PLUGININIT mInitializeFunc;
