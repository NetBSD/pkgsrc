$NetBSD: patch-gmic-qt_gmic__qt.pro,v 1.1 2020/05/26 11:28:04 joerg Exp $

--- gmic-qt/gmic_qt.pro.orig	2020-05-26 01:42:41.240133823 +0000
+++ gmic-qt/gmic_qt.pro
@@ -227,12 +227,6 @@ win32:equals(LTO,"on") {
     LTO = off
 }
 
-!win32:CONFIG(release, debug|release):gcc|clang:equals(LTO,"on") {
-    message("Link Time Optimizer enabled")
-    QMAKE_CXXFLAGS_RELEASE += -flto
-    QMAKE_LFLAGS_RELEASE += -flto
-}
-
 DEFINES += gmic_gui gmic_build gmic_is_parallel cimg_use_abort
 
 INCLUDEPATH	+= $$PWD $$PWD/src $$GMIC_PATH
