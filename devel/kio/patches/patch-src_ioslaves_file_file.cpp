$NetBSD: patch-src_ioslaves_file_file.cpp,v 1.2 2019/04/25 20:50:23 markd Exp $

Properly comment out debug code.

--- src/ioslaves/file/file.cpp.orig	2019-04-07 07:29:13.000000000 +0000
+++ src/ioslaves/file/file.cpp
@@ -1168,7 +1168,7 @@ void FileProtocol::unmount(const QString
 
     if (volmgt_running()) {
         // qDebug() << "VOLMGT: looking for "
-                << _point.toLocal8Bit();
+        //        << _point.toLocal8Bit();
 
         if ((mnttab = QT_FOPEN(MNTTAB, "r")) == nullptr) {
             err = QLatin1String("could not open mnttab");
@@ -1196,8 +1196,8 @@ void FileProtocol::unmount(const QString
         if (devname == nullptr) {
             err = QLatin1String("not in mnttab");
             // qDebug() << "VOLMGT: "
-                    << QFile::encodeName(_point).data()
-                    << ": " << err;
+            //        << QFile::encodeName(_point).data()
+            //        << ": " << err;
             error(KIO::ERR_CANNOT_UNMOUNT, err);
             return;
         }
