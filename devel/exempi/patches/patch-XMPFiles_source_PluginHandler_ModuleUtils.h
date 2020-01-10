$NetBSD: patch-XMPFiles_source_PluginHandler_ModuleUtils.h,v 1.1 2020/01/10 21:11:14 joerg Exp $

--- XMPFiles/source/PluginHandler/ModuleUtils.h.orig	2020-01-09 00:04:52.760646486 +0000
+++ XMPFiles/source/PluginHandler/ModuleUtils.h
@@ -19,7 +19,7 @@ typedef HMODULE OS_ModuleRef;
 #include <memory>
 typedef CFBundleRef OS_ModuleRef;
 #elif XMP_UNIXBuild
-#include <tr1/memory>
+#include <memory>
 typedef void* OS_ModuleRef;
 #else
 #error	Unsupported operating system
