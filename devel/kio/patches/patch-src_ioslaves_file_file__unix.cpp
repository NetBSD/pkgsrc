$NetBSD: patch-src_ioslaves_file_file__unix.cpp,v 1.1 2018/06/15 13:46:48 jperkin Exp $

Fix HAVE_DIRENT_D_TYPE define.

--- src/ioslaves/file/file_unix.cpp.orig	2018-03-04 11:01:29.000000000 +0000
+++ src/ioslaves/file/file_unix.cpp
@@ -463,9 +463,7 @@ void FileProtocol::listDir(const QUrl &u
     //qDebug() << "========= LIST " << url << "details=" << details << " =========";
     UDSEntry entry;
 
-#ifndef HAVE_DIRENT_D_TYPE
     QT_STATBUF st;
-#endif
     QT_DIRENT *ep;
     while ((ep = QT_READDIR(dp)) != nullptr) {
         entry.clear();
@@ -484,7 +482,7 @@ void FileProtocol::listDir(const QUrl &u
          */
         if (details == 0) {
             entry.insert(KIO::UDSEntry::UDS_NAME, filename);
-#ifdef HAVE_DIRENT_D_TYPE
+#if HAVE_DIRENT_D_TYPE
             entry.insert(KIO::UDSEntry::UDS_FILE_TYPE,
                          (ep->d_type == DT_DIR) ? S_IFDIR : S_IFREG);
             const bool isSymLink = (ep->d_type == DT_LNK);
