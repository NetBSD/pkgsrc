$NetBSD: patch-mozilla_dom_plugins_ipc_PluginModuleChild.h,v 1.1 2017/04/27 13:38:18 ryoon Exp $

--- mozilla/dom/plugins/ipc/PluginModuleChild.h.orig	2016-04-07 21:33:30.000000000 +0000
+++ mozilla/dom/plugins/ipc/PluginModuleChild.h
@@ -281,7 +281,7 @@ private:
 
     // we get this from the plugin
     NP_PLUGINSHUTDOWN mShutdownFunc;
-#if defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
     NP_PLUGINUNIXINIT mInitializeFunc;
 #elif defined(OS_WIN) || defined(OS_MACOSX)
     NP_PLUGININIT mInitializeFunc;
