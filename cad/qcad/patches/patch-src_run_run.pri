$NetBSD: patch-src_run_run.pri,v 1.4 2019/12/29 14:18:20 plunky Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target. Do not copy Qt plugins

--- src/run/run.pri.orig	2019-07-18 15:47:56.000000000 +0000
+++ src/run/run.pri
@@ -45,9 +45,12 @@ else {
         TARGET = $${RLIBNAME}-bin
     }
 }
+TARGET = $${RLIBNAME}
+INSTALLS += target
+target.path = $${PREFIX}/bin
 
-# copy Qt plugins to QCAD plugin folder:
-!build_pass {
+# do not copy Qt plugins to QCAD plugin folder:
+do_not {
     macx {
         FILES = \
             imageformats/libqgif.dylib \
