$NetBSD: patch-dom_plugins_ipc_PluginModuleChild.cpp,v 1.1.1.1 2012/03/15 08:58:28 ryoon Exp $

--- dom/plugins/ipc/PluginModuleChild.cpp.orig	2012-03-09 22:20:12.000000000 +0000
+++ dom/plugins/ipc/PluginModuleChild.cpp
@@ -236,7 +236,7 @@ PluginModuleChild::Init(const std::strin
 
     // TODO: use PluginPRLibrary here
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     mShutdownFunc =
         (NP_PLUGINSHUTDOWN) PR_FindFunctionSymbol(mLibrary, "NP_Shutdown");
 
@@ -1824,7 +1824,7 @@ PluginModuleChild::AnswerNP_GetEntryPoin
     PLUGIN_LOG_DEBUG_METHOD;
     AssertPluginThread();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     return true;
 #elif defined(OS_WIN) || defined(OS_MACOSX)
     *_retval = mGetEntryPointsFunc(&mFunctions);
@@ -1851,7 +1851,7 @@ PluginModuleChild::AnswerNP_Initialize(N
     SendBackUpXResources(FileDescriptor(xSocketFd, false/*don't close*/));
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     *_retval = mInitializeFunc(&sBrowserFuncs, &mFunctions);
     return true;
 #elif defined(OS_WIN) || defined(OS_MACOSX)
