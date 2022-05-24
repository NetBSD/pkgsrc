$NetBSD: patch-src_run_main.cpp,v 1.4 2022/05/24 05:17:12 plunky Exp $

don't overwrite the plugins directory: remove the applicationDir and add the pluginPaths

--- src/run/main.cpp.orig	2021-10-11 12:27:59.000000000 +0000
+++ src/run/main.cpp
@@ -268,7 +268,12 @@ int main(int argc, char *argv[]) {
         qWarning() << "No plugin paths found";
         return -1;
     }
-    app->setLibraryPaths(pluginPaths);
+
+    // for pkgsrc, skip the applicationDir and add the Plugin paths
+    app->removeLibraryPath(app->applicationDirPath());
+    foreach (const QString &path, pluginPaths)
+	app->addLibraryPath(path);
+
 
     // make sure basic entities are initialized before loading plugins:
     RDimStyleData::initDefaults();
