$NetBSD: patch-plugins_krarc_krarc.cpp,v 1.1 2025/09/03 14:54:00 kikadf Exp $

* Fix folder view for zip archives
  Parch imported from FreeBSD,
  https://github.com/freebsd/freebsd-ports/commit/cb09c762742f00418056761ba8e7dc769473beef

--- plugins/krarc/krarc.cpp.orig	2025-09-03 09:00:22.473890009 +0000
+++ plugins/krarc/krarc.cpp
@@ -1568,10 +1568,10 @@ KIO::WorkerResult kio_krarcProtocol::ini
 
     if (arcType == "zip") {
         noencoding = true;
-        cmd = fullPathName("unzip");
-        listCmd << fullPathName("unzip") << "-ZTs-z-t-h";
-        getCmd << fullPathName("unzip") << "-p";
-        copyCmd << fullPathName("unzip") << "-jo";
+        cmd = QString("@PREFIX@/bin/unzip");
+        listCmd << cmd << "-ZTs-z-t-h";
+        getCmd << cmd << "-p";
+        copyCmd << cmd << "-jo";
 
         if (QStandardPaths::findExecutable(QStringLiteral("zip")).isEmpty()) {
             delCmd = QStringList();
