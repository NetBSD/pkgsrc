$NetBSD: patch-src_kioworkers_file_file__unix.cpp,v 1.1 2024/05/26 11:42:12 markd Exp $

Fix HAVE_DIRENT_D_TYPE type.

--- src/kioworkers/file/file_unix.cpp.orig	2022-04-02 10:22:23.000000000 +0000
+++ src/kioworkers/file/file_unix.cpp
@@ -1088,7 +1088,7 @@ void FileProtocol::listDir(const QUrl &u
     // qDebug() << "========= LIST " << url << "details=" << details << " =========";
     UDSEntry entry;
 
-#ifndef HAVE_DIRENT_D_TYPE
+#if !HAVE_DIRENT_D_TYPE
     QT_STATBUF st;
 #endif
     QT_DIRENT *ep;
@@ -1109,7 +1109,7 @@ void FileProtocol::listDir(const QUrl &u
          */
         if (details == KIO::StatBasic) {
             entry.fastInsert(KIO::UDSEntry::UDS_NAME, filename);
-#ifdef HAVE_DIRENT_D_TYPE
+#if HAVE_DIRENT_D_TYPE
             entry.fastInsert(KIO::UDSEntry::UDS_FILE_TYPE, (ep->d_type == DT_DIR) ? S_IFDIR : S_IFREG);
             const bool isSymLink = (ep->d_type == DT_LNK);
 #else
