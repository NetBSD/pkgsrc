$NetBSD: patch-src_core_RS.cpp,v 1.3 2020/04/07 08:18:22 plunky Exp $

fix hardcoded paths

--- src/core/RS.cpp.orig	2020-03-17 10:40:38.000000000 +0000
+++ src/core/RS.cpp
@@ -139,44 +139,10 @@
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
+    //QString appDirName = QSettings.applicationName();
+    dirList.append("@PREFIX@/lib/qcad/" + subDirectory);
+    dirList.append("@PREFIX@/share/qcad/" + subDirectory);
+    dirList.append(QDir::homePath() + "/.qcad/" + subDirectory);
 
     // add a path to users home (config dir) to be used to extend pattern, linetypes, etc.
     dirList.append(RSettings::getPath() + "/" + subDirectory);
