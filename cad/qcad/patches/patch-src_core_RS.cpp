$NetBSD: patch-src_core_RS.cpp,v 1.5 2025/08/19 12:52:17 plunky Exp $

fix hardcoded paths

--- src/core/RS.cpp.orig	2025-06-10 07:10:41.000000000 +0000
+++ src/core/RS.cpp
@@ -168,6 +168,7 @@ bool RS::compare(const QPair<QVariant, R
 QStringList RS::getDirectoryList(const QString& subDirectory) {
     QStringList dirList;
 
+#if 0
     QString appDir = QCoreApplication::applicationDirPath();
     QFileInfo fi(appDir);
     if (fi.fileName() == "debug" || fi.fileName() == "release") {
@@ -206,6 +207,11 @@ QStringList RS::getDirectoryList(const Q
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
