$NetBSD: patch-src_core_StelFileMgr.cpp,v 1.3 2022/10/03 09:07:03 adam Exp $

On Darwin, do not use bundles.

--- src/core/StelFileMgr.cpp.orig	2022-09-21 12:07:19.000000000 +0000
+++ src/core/StelFileMgr.cpp
@@ -103,7 +103,7 @@ void StelFileMgr::init()
 	}	
 	else
 	{
-	#if defined(Q_OS_MACOS)
+	#if 0
 		QString relativePath = "/../Resources";
 		if (QCoreApplication::applicationDirPath().contains("src")) {
 			relativePath = "/../..";
