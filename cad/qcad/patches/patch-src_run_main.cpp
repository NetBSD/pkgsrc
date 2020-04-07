$NetBSD: patch-src_run_main.cpp,v 1.2 2020/04/07 08:18:22 plunky Exp $

don't overwrite the plugins directory: remove the applicationDir and add the pluginPaths

--- src/run/main.cpp.orig	2020-03-17 10:40:38.000000000 +0000
+++ src/run/main.cpp
@@ -237,7 +237,11 @@
         qWarning() << "No plugin paths found";
         return -1;
     }
-    app->setLibraryPaths(pluginPaths);
+
+    // for pkgsrc, skip the applicationDir and add the Plugin paths
+    app->removeLibraryPath(app->applicationDirPath());
+    foreach (const QString &path, pluginPaths)
+    	app->addLibraryPath(path);
 
     RSettings::setApplicationNameOverride("QCAD3");
 
