$NetBSD: patch-shared.pri,v 1.1 2016/08/30 10:56:04 plunky Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- shared.pri.orig	2016-07-01 07:13:14.000000000 +0000
+++ shared.pri
@@ -158,7 +158,8 @@ QMAKE_TARGET_PRODUCT = QCAD Application
 DESTDIR = $$PWD/$$ROUTDIR
 UI_DIR = .ui

-LIBS += -L$$PWD/$$ROUTDIR
+PREFIX= @PREFIX@
+target.path = $${PREFIX}/lib

 CONFIG(debug, debug|release) {
     !win32 {
