$NetBSD: patch-src_run_main.cpp,v 1.1 2019/12/29 14:18:20 plunky Exp $

don't overwrite the plugins directory: remove the applicationDir and add the pluginPaths

--- src/run/main.cpp.orig	2019-12-22 19:09:21.954519285 +0000
+++ src/run/main.cpp
@@ -237,7 +237,11 @@ int main(int argc, char *argv[]) {
         qWarning() << "No plugin paths found";
         return -1;
     }
-    app->setLibraryPaths(pluginPaths);
+
+    // for pkgsrc, skip the applicationDir and add the Plugin paths
+    app->removeLibraryPath(app->applicationDirPath());
+    foreach (const QString &path, pluginPaths)
+    	app->addLibraryPath(path);
 
     RMath::init();
     RFontList::init();
