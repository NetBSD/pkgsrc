$NetBSD: patch-src_core_RS.cpp,v 1.2 2019/09/05 13:39:10 nia Exp $

fix hardcoded paths

--- src/core/RS.cpp.orig	2019-07-18 15:47:56.000000000 +0000
+++ src/core/RS.cpp
@@ -139,48 +139,9 @@ bool RS::compare(const QPair<QVariant, R
 QStringList RS::getDirectoryList(const QString& subDirectory) {
     QStringList dirList;
 
-    QString appDir = QCoreApplication::applicationDirPath();
-    QFileInfo fi(appDir);
-    if (fi.fileName() == "debug" || fi.fileName() == "release") {
-        appDir = fi.absolutePath();
-    }
-
-#ifdef Q_OS_MAC
-    // Mac OS X app bundle:
-    dirList.append(appDir + "/../Resources/" + subDirectory);
-    dirList.append(appDir + "/../../../" + subDirectory);
-    dirList.append(QDir::currentPath() + "/" + subDirectory);
-#else
-    dirList.append(appDir + "/" + subDirectory);
-#endif
-
-    /*
-#ifdef Q_OS_MAC
-    if (subDirectory!="library") {
-#endif
-        //local (application) directory has priority over other dirs:
-        dirList.append(appDir + QDir::separator() + subDirectory);
-
- #ifdef Q_OS_LINUX
-        QString appDirName = QSettings.applicationName();
-        // Redhat style:
-        dirList.append("/usr/share/" + appDirName + "/" + subDirectory);
-
-        // SuSE style:
-        dirList.append("/usr/X11R6/" + appDirName + "/" + subDirectory);
-
-        dirList.append("/usr/X11R6/share/" + appDirName + "/" + subDirectory);
-        dirList.append(QDir::homePath() + "/." + appDirName + "/" + subDirectory);
-#endif
-
-#ifdef Q_OS_MAC
-    }
-#endif
-    */
-
-    // TODO: add a path to users home to be used to extend pattern, etc.
-    //QString appDirName = QSettings.applicationName();
-    //dirList.append(RSettings::getHomeLocation() + "/." + appDirName + "/" + subDirectory);
+    dirList.append("@PREFIX@/lib/qcad/" + subDirectory);
+    dirList.append("@PREFIX@/share/qcad/" + subDirectory);
+    dirList.append(QDir::homePath() + "/.qcad/" + subDirectory);
 
     QStringList ret;
     for (int i=0; i<dirList.size(); i++) {
