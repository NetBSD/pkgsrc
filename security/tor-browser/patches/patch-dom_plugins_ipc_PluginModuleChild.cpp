$NetBSD: patch-dom_plugins_ipc_PluginModuleChild.cpp,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- dom/plugins/ipc/PluginModuleChild.cpp.orig	2015-03-27 02:20:27.000000000 +0000
+++ dom/plugins/ipc/PluginModuleChild.cpp
@@ -320,7 +320,7 @@ PluginModuleChild::InitForChrome(const s
 
     // TODO: use PluginPRLibrary here
 
-#if defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
     mShutdownFunc =
         (NP_PLUGINSHUTDOWN) PR_FindFunctionSymbol(mLibrary, "NP_Shutdown");
 
@@ -1882,7 +1882,7 @@ PluginModuleChild::AnswerNP_GetEntryPoin
     AssertPluginThread();
     MOZ_ASSERT(mIsChrome);
 
-#if defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
     return true;
 #elif defined(OS_WIN) || defined(OS_MACOSX)
     *_retval = mGetEntryPointsFunc(&mFunctions);
@@ -1927,7 +1927,7 @@ PluginModuleChild::DoNP_Initialize(const
 #endif
 
     NPError result;
-#if defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
     result = mInitializeFunc(&sBrowserFuncs, &mFunctions);
 #elif defined(OS_WIN) || defined(OS_MACOSX)
     result = mInitializeFunc(&sBrowserFuncs);
