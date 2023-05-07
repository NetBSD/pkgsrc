$NetBSD: patch-server_src_storage_dbconfigmysql.cpp,v 1.1 2023/05/07 19:50:48 nikita Exp $

reproducible builds patch (timestamps).

--- server/src/storage/dbconfigmysql.cpp.orig	2023-05-07 21:40:51.011950361 +0200
+++ server/src/storage/dbconfigmysql.cpp	2023-05-07 21:42:10.577027826 +0200
@@ -210,8 +210,7 @@
   bool confUpdate = false;
   QFile actualFile ( actualConfig );
   // update conf only if either global (or local) is newer than actual
-  if ( ( QFileInfo( globalConfig ).lastModified() > QFileInfo( actualFile ).lastModified() ) ||
-       ( QFileInfo( localConfig ).lastModified()  > QFileInfo( actualFile ).lastModified() ) ) {
+  if (true) {
     QFile globalFile( globalConfig );
     QFile localFile ( localConfig );
     if ( globalFile.open( QFile::ReadOnly ) && actualFile.open( QFile::WriteOnly ) ) {
