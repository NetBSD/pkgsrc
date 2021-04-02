$NetBSD: patch-src_run_main.cpp,v 1.3 2021/04/02 20:27:12 plunky Exp $

don't overwrite the plugins directory: remove the applicationDir and add the pluginPaths

--- src/run/main.cpp.orig	2020-11-03 12:42:11.000000000 +0000
+++ src/run/main.cpp
@@ -253,7 +253,11 @@ int main(int argc, char *argv[]) {
         qWarning() << "No plugin paths found";
         return -1;
     }
-    app->setLibraryPaths(pluginPaths);
+
+    // for pkgsrc, skip the applicationDir and add the Plugin paths
+    app->removeLibraryPath(app->applicationDirPath());
+    foreach (const QString &path, pluginPaths)
+	app->addLibraryPath(path);
 
     RMath::init();
     RFontList::init();
