$NetBSD: patch-src_core_StelFileMgr.cpp,v 1.2 2019/03/26 11:15:37 adam Exp $

On Darwin, do not use bundles.

--- src/core/StelFileMgr.cpp.orig	2019-03-23 14:43:26.000000000 +0000
+++ src/core/StelFileMgr.cpp
@@ -101,7 +101,7 @@ void StelFileMgr::init()
 	}	
 	else
 	{
-	#if defined(Q_OS_MAC)
+	#if 0
 		QString relativePath = "/../Resources";
 		if (QCoreApplication::applicationDirPath().contains("src")) {
 			relativePath = "/../..";
