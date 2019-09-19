$NetBSD: patch-src_run_run.pri,v 1.3 2019/09/19 21:59:36 nia Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

only link to the Qt plugins, no need to copy them over

--- src/run/run.pri.orig	2019-07-18 15:47:56.000000000 +0000
+++ src/run/run.pri
@@ -45,6 +45,9 @@ else {
         TARGET = $${RLIBNAME}-bin
     }
 }
+TARGET = $${RLIBNAME}
+INSTALLS += target
+target.path = $${PREFIX}/bin
 
 # copy Qt plugins to QCAD plugin folder:
 !build_pass {
@@ -109,7 +112,7 @@ else {
 
         for(FILE,FILES) {
             !exists("$${DESTDIR}/../plugins/$${FILE}") {
-                system(cp "$$[QT_INSTALL_PLUGINS]/$${FILE}" "$${DESTDIR}/../plugins/$${FILE}")
+                system(ln -sf "$$[QT_INSTALL_PLUGINS]/$${FILE}" "../../plugins/$${FILE}")
             }
         }
 
@@ -117,7 +120,6 @@ else {
             system(cp "$$[QT_INSTALL_PLUGINS]/platforms/libqxcb.so" "$${DESTDIR}/../platforms")
             system(cp "$$[QT_INSTALL_PLUGINS]/platforms/libqoffscreen.so" "$${DESTDIR}/../platforms")
             system(cp "$$[QT_INSTALL_PLUGINS]/platforms/libqminimal.so" "$${DESTDIR}/../platforms")
-            system(cp "$$[QT_INSTALL_PLUGINS]/platforms/libqlinuxfb.so" "$${DESTDIR}/../platforms")
             system(cp "$$[QT_INSTALL_PLUGINS]/platforminputcontexts/*.so" "$${DESTDIR}/../platforminputcontexts")
             system(cp "$$[QT_INSTALL_PLUGINS]/xcbglintegrations/*.so" "$${DESTDIR}/../xcbglintegrations")
         }
