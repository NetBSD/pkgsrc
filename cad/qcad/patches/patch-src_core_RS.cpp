$NetBSD: patch-src_core_RS.cpp,v 1.4 2022/05/24 05:17:12 plunky Exp $

fix hardcoded paths

--- src/core/RS.cpp.orig	2020-03-17 10:40:38.000000000 +0000
+++ src/core/RS.cpp
@@ -149,6 +149,7 @@
 QStringList RS::getDirectoryList(const QString& subDirectory) {
     QStringList dirList;
 
+#if 0
     QString appDir = QCoreApplication::applicationDirPath();
     QFileInfo fi(appDir);
     if (fi.fileName() == "debug" || fi.fileName() == "release") {
@@ -187,6 +188,11 @@
     }
 #endif
     */
+#endif
+
+    dirList.append("@PREFIX@/lib/qcad/" + subDirectory);
+    dirList.append("@PREFIX@/share/qcad/" + subDirectory);
+    dirList.append(QDir::homePath() + "/.qcad/" + subDirectory);
 
     // add a path to users home (config dir) to be used to extend pattern, linetypes, etc.
     dirList.append(RSettings::getPath() + "/" + subDirectory);
