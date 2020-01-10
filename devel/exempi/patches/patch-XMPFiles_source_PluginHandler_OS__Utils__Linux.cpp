$NetBSD: patch-XMPFiles_source_PluginHandler_OS__Utils__Linux.cpp,v 1.1 2020/01/10 21:11:14 joerg Exp $

--- XMPFiles/source/PluginHandler/OS_Utils_Linux.cpp.orig	2020-01-09 00:06:19.570733059 +0000
+++ XMPFiles/source/PluginHandler/OS_Utils_Linux.cpp
@@ -28,7 +28,7 @@ typedef std::map<OS_ModuleRef, std::stri
 static ResourceFileToPathMap						sMapResourceFileToPath;
 static XMP_ReadWriteLock							sMapModuleRWLock;
 
-typedef std::tr1::shared_ptr<int>					FilePtr;
+typedef std::shared_ptr<int>					FilePtr;
 
 static std::string GetModulePath( OS_ModuleRef inOSModule );
 /** ************************************************************************************************************************
