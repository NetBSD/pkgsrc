$NetBSD: patch-src_lib_io_kfilesystemtype.cpp,v 1.1 2024/05/26 11:26:13 markd Exp $

Fix #endif logic.

--- src/lib/io/kfilesystemtype.cpp.orig	2024-05-03 12:24:08.000000000 +0000
+++ src/lib/io/kfilesystemtype.cpp
@@ -222,7 +222,6 @@ KFileSystemType::Type determineFileSyste
     return kde_typeFromName(buf.f_basetype);
 #endif
 }
-#endif
 #else
 KFileSystemType::Type determineFileSystemTypeImpl(const QByteArray &path)
 {
@@ -230,6 +229,7 @@ KFileSystemType::Type determineFileSyste
     return KFileSystemType::Unknown;
 }
 #endif
+#endif
 
 KFileSystemType::Type KFileSystemType::fileSystemType(const QString &path)
 {
