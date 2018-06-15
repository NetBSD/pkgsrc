$NetBSD: patch-src_ioslaves_file_file.cpp,v 1.1 2018/06/15 13:46:48 jperkin Exp $

Properly comment out debug code.

--- src/ioslaves/file/file.cpp.orig	2018-03-04 11:01:29.000000000 +0000
+++ src/ioslaves/file/file.cpp
@@ -1148,7 +1148,7 @@ void FileProtocol::unmount(const QString
 
     if (volmgt_running()) {
         // qDebug() << "VOLMGT: looking for "
-                << _point.toLocal8Bit();
+        //        << _point.toLocal8Bit();
 
         if ((mnttab = QT_FOPEN(MNTTAB, "r")) == NULL) {
             err = QLatin1String("could not open mnttab");
@@ -1176,8 +1176,8 @@ void FileProtocol::unmount(const QString
         if (devname == NULL) {
             err = QLatin1String("not in mnttab");
             // qDebug() << "VOLMGT: "
-                    << QFile::encodeName(_point).data()
-                    << ": " << err;
+            //        << QFile::encodeName(_point).data()
+            //        << ": " << err;
             error(KIO::ERR_CANNOT_UNMOUNT, err);
             return;
         }
