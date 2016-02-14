$NetBSD: patch-dom_plugins_ipc_PluginProcessChild.cpp,v 1.1 2016/02/14 07:30:54 ryoon Exp $

Just because OS_ARCH is Darwin does not mean
libplugin_child_interpose.dylib is used.

--- dom/plugins/ipc/PluginProcessChild.cpp.orig	2015-02-17 21:40:45.000000000 +0000
+++ dom/plugins/ipc/PluginProcessChild.cpp
@@ -56,7 +56,7 @@ PluginProcessChild::Init()
 {
     nsDebugImpl::SetMultiprocessMode("NPAPI");
 
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
     // Remove the trigger for "dyld interposing" that we added in
     // GeckoChildProcessHost::PerformAsyncLaunchInternal(), in the host
     // process just before we were launched.  Dyld interposing will still
