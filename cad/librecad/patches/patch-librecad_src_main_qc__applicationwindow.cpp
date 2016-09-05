$NetBSD: patch-librecad_src_main_qc__applicationwindow.cpp,v 1.1 2016/09/05 21:13:21 plunky Exp $

ignore files in the plugins directory that do not contain '.so', as
pkgsrc leaves some .la files there

--- librecad/src/main/qc_applicationwindow.cpp.orig	2016-06-20 18:43:27.000000000 +0000
+++ librecad/src/main/qc_applicationwindow.cpp
@@ -385,6 +385,9 @@ void QC_ApplicationWindow::loadPlugins()
             #ifdef Q_OS_MAC
             if (!fileName.contains(".dylib"))
                 continue;
+            #else if defined(Q_OS_UNIX)
+            if (!fileName.contains(".so"))
+                continue;
             #endif
 
             if (loadedPluginFileNames.contains(fileName)) {
