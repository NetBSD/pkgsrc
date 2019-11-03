$NetBSD: patch-src_smalldialogs.cpp,v 1.1 2019/11/03 04:01:32 gutteridge Exp $

Fix the file dialog list in the "small dialog window", taken from:
https://github.com/KDE/kdiff3/commit/fa6d0d8a0505a7e7cf4b0d743b1a222f3a9940ce

--- src/smalldialogs.cpp.orig	2019-05-18 01:01:30.000000000 +0000
+++ src/smalldialogs.cpp
@@ -231,8 +231,8 @@ void OpenDialog::selectURL(QComboBox* pL
 
     currentUrl = QUrl::fromUserInput(current, QString(), QUrl::AssumeLocalFile);
     QUrl newURL = bDir ? QFileDialog::getExistingDirectoryUrl(this, i18n("Open Directory"), currentUrl)
-                       : bSave ? QFileDialog::getSaveFileUrl(this, i18n("Select Output File"), currentUrl, QLatin1Literal("all/allfiles"))
-                               : QFileDialog::getOpenFileUrl(this, i18n("Open File"), currentUrl, QLatin1Literal("all/allfiles"));
+                       : bSave ? QFileDialog::getSaveFileUrl(this, i18n("Select Output File"), currentUrl, i18n("All files (*)"))
+                               : QFileDialog::getOpenFileUrl(this, i18n("Open File"), currentUrl, i18n("All files (*)"));
     if(!newURL.isEmpty()) {
         /*
         Since we are selecting a directory open in the parent directory
