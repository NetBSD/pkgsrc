$NetBSD: patch-mozilla_dom_plugins_ipc_PluginProcessChild.cpp,v 1.1 2017/04/27 13:38:18 ryoon Exp $

--- mozilla/dom/plugins/ipc/PluginProcessChild.cpp.orig	2016-04-07 21:33:30.000000000 +0000
+++ mozilla/dom/plugins/ipc/PluginProcessChild.cpp
@@ -46,7 +46,7 @@ PluginProcessChild::Init()
 {
     nsDebugImpl::SetMultiprocessMode("NPAPI");
 
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
     // Remove the trigger for "dyld interposing" that we added in
     // GeckoChildProcessHost::PerformAsyncLaunchInternal(), in the host
     // process just before we were launched.  Dyld interposing will still
