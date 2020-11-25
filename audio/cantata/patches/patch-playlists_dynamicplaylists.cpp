$NetBSD: patch-playlists_dynamicplaylists.cpp,v 1.1 2020/11/25 20:59:37 wiz Exp $

Add missing semicolon.

--- playlists/dynamicplaylists.cpp.orig	2020-08-23 10:14:57.000000000 +0000
+++ playlists/dynamicplaylists.cpp
@@ -361,8 +361,8 @@ int DynamicPlaylists::getPid() const
 }
 
 static QString helperScript() {
-    QString script = QLatin1String("cantata-dynamic")
-    QString local = fixPath(QCoreApplication::applicationDirPath())+script;
+    QString script = QLatin1String("cantata-dynamic");
+    QString local = Utils::fixPath(QCoreApplication::applicationDirPath())+script;
     if (QFile::exists(local)) {
         return local;
     }
