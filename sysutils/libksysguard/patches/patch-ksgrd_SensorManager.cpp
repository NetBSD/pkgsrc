$NetBSD: patch-ksgrd_SensorManager.cpp,v 1.1 2023/10/14 03:37:59 markd Exp $

--- ksgrd/SensorManager.cpp.orig	2022-07-11 10:53:39.000000000 +0000
+++ ksgrd/SensorManager.cpp
@@ -74,6 +74,7 @@ void SensorManager::retranslate()
     mDict.insert(QStringLiteral("wired"), i18n("Wired Memory"));
     mDict.insert(QStringLiteral("execpages"), i18n("Exec Pages"));
     mDict.insert(QStringLiteral("filepages"), i18n("File Pages"));
+    mDict.insert(QStringLiteral("anonpages"), i18n("Anon Pages"));
 
     /* Processes */
     mDict.insert(QStringLiteral("processes"), i18n("Processes"));
