$NetBSD: patch-src_core_StelFileMgr.cpp,v 1.4 2026/06/25 08:32:03 adam Exp $

On Darwin, do not use bundles.

--- src/core/StelFileMgr.cpp.orig	2026-06-24 16:39:30.000000000 +0000
+++ src/core/StelFileMgr.cpp
@@ -116,7 +116,7 @@ void StelFileMgr::init()
 		searchPaths += info.absoluteFilePath() + "/0/stellarium";
 	}
 	searchPaths += "/sdcard/stellarium";
-#elif defined(Q_OS_MACOS)
+#elif 0
 	QString relativePath = "/../Resources";
 	if (QCoreApplication::applicationDirPath().contains("src")) {
 		relativePath = "/../..";
