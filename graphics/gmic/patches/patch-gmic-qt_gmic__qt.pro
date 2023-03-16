$NetBSD: patch-gmic-qt_gmic__qt.pro,v 1.2 2023/03/16 07:15:48 wiz Exp $

Link against libX11 on everything except macOS which might not use X11.

Stop using lto by default.

--- gmic-qt/gmic_qt.pro.orig	2020-03-28 13:25:12.000000000 +0000
+++ gmic-qt/gmic_qt.pro
@@ -147,7 +147,7 @@ win32 {
  DEFINES += cimg_display=2
 }
 
-linux {
+!macx {
   DEFINES += _IS_LINUX_
   PKGCONFIG += x11
   message( Linux platform )
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
