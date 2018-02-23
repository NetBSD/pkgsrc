$NetBSD: patch-src_core_StelFileMgr.cpp,v 1.1 2018/02/23 11:29:39 adam Exp $

On Darwin, do not use bundles.

--- src/core/StelFileMgr.cpp.orig	2018-02-23 09:03:47.000000000 +0000
+++ src/core/StelFileMgr.cpp
@@ -86,7 +86,7 @@ void StelFileMgr::init()
 	}
 	else
 	{
-	#if defined(Q_OS_MAC)
+	#if 0
 		QString relativePath = "/../Resources";
 		if (QCoreApplication::applicationDirPath().contains("src")) {
 			relativePath = "/../..";
