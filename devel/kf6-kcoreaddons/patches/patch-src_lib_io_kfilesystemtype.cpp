$NetBSD: patch-src_lib_io_kfilesystemtype.cpp,v 1.2 2026/09/06 10:05:12 markd Exp $

Fix #endif logic.

--- src/lib/io/kfilesystemtype.cpp.orig	2026-08-07 20:39:44.000000000 +0000
+++ src/lib/io/kfilesystemtype.cpp
@@ -268,7 +268,6 @@ static KFileSystemType::Type determineFi
         return KFileSystemType::Other;
     }
 }
-#endif
 #else
 KFileSystemType::Type determineFileSystemTypeImpl(const QByteArray &path)
 {
@@ -276,6 +275,7 @@ KFileSystemType::Type determineFileSyste
     return KFileSystemType::Unknown;
 }
 #endif
+#endif
 
 KFileSystemType::Type KFileSystemType::fileSystemType(const QString &path)
 {
