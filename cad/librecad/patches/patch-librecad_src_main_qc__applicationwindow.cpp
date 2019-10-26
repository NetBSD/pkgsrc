$NetBSD: patch-librecad_src_main_qc__applicationwindow.cpp,v 1.2 2019/10/26 12:23:01 kamil Exp $

ignore files in the plugins directory that do not contain '.so', as
pkgsrc leaves some .la files there

--- librecad/src/main/qc_applicationwindow.cpp.orig	2018-02-15 20:54:45.000000000 +0000
+++ librecad/src/main/qc_applicationwindow.cpp
@@ -399,6 +399,10 @@ void QC_ApplicationWindow::loadPlugins()
             if (!fileName.contains(".dylib"))
                 continue;
             #endif
+            #if defined(Q_OS_UNIX)
+            if (!fileName.contains(".so"))
+                continue;
+            #endif
             #ifdef Q_OS_WIN32
             if (!fileName.contains(".dll"))
                 continue;
