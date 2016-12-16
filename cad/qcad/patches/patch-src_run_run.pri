$NetBSD: patch-src_run_run.pri,v 1.2 2016/12/16 11:16:32 plunky Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

only link to the Qt plugins, no need to copy them over

--- src/run/run.pri.orig	2016-07-01 07:13:14.000000000 +0000
+++ src/run/run.pri
@@ -39,6 +39,9 @@ else {
         TARGET = $${RLIBNAME}-bin
     }
 }
+TARGET = $${RLIBNAME}
+INSTALLS += target
+target.path = $${PREFIX}/bin
 
 # copy Qt plugins to QCAD plugin folder:
 !build_pass {
@@ -102,7 +105,7 @@ else {
 
         for(FILE,FILES) {
             !exists("$${DESTDIR}/../plugins/$${FILE}") {
-                system(cp "$$[QT_INSTALL_PLUGINS]/$${FILE}" "$${DESTDIR}/../plugins/$${FILE}")
+                system(ln -sf "$$[QT_INSTALL_PLUGINS]/$${FILE}" "../../plugins/$${FILE}")
             }
         }
 
