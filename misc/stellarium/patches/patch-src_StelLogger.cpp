$NetBSD: patch-src_StelLogger.cpp,v 1.1 2023/09/30 17:14:46 adam Exp $

Fix build for BSD.

--- src/StelLogger.cpp.orig	2023-09-30 18:40:03.709676791 +0000
+++ src/StelLogger.cpp
@@ -214,11 +214,7 @@ void StelLogger::init(const QString& log
 	dmesg.waitForStarted();
 	dmesg.waitForFinished();
 	const QString dmesgData(dmesg.readAll());
-	#if (QT_VERSION>=QT_VERSION_CHECK(5, 14, 0))
-	QStringList dmesgLines = dmesgData.split('\n', QString::SkipEmptyParts);
-	#else
 	QStringList dmesgLines = dmesgData.split('\n', Qt::SkipEmptyParts);
-	#endif
 	for (int i = 0; i<dmesgLines.size(); i++)
 	{
 		if (dmesgLines.at(i).contains("memory"))
