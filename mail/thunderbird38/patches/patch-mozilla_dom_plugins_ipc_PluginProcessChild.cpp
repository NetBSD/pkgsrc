$NetBSD: patch-mozilla_dom_plugins_ipc_PluginProcessChild.cpp,v 1.1 2016/04/17 18:22:21 ryoon Exp $

--- mozilla/dom/plugins/ipc/PluginProcessChild.cpp.orig	2015-06-08 17:49:29.000000000 +0000
+++ mozilla/dom/plugins/ipc/PluginProcessChild.cpp
@@ -56,7 +56,7 @@ PluginProcessChild::Init()
 {
     nsDebugImpl::SetMultiprocessMode("NPAPI");
 
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
     // Remove the trigger for "dyld interposing" that we added in
     // GeckoChildProcessHost::PerformAsyncLaunchInternal(), in the host
     // process just before we were launched.  Dyld interposing will still
