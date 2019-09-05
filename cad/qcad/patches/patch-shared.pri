$NetBSD: patch-shared.pri,v 1.2 2019/09/05 13:39:10 nia Exp $

fix build for pkgsrc, by allowing qmake to link binaries in situ
and create an install target

--- shared.pri.orig	2019-07-18 15:47:56.000000000 +0000
+++ shared.pri
@@ -178,7 +178,8 @@ QMAKE_TARGET_PRODUCT = QCAD Application 
 DESTDIR = $$PWD/$$ROUTDIR
 UI_DIR = .ui
 
-LIBS += -L$$PWD/$$ROUTDIR
+PREFIX= @PREFIX@
+target.path = $${PREFIX}/lib
 
 CONFIG(debug, debug|release) {
     !win32 {
