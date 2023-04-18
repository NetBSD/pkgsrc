$NetBSD: patch-gmic-qt_gmic__qt.pro,v 1.3 2023/04/18 16:00:08 wiz Exp $

Link against libX11 on everything except macOS which might not use X11.

--- gmic-qt/gmic_qt.pro.orig	2023-04-04 16:20:27.000000000 +0000
+++ gmic-qt/gmic_qt.pro
@@ -180,7 +180,7 @@ win32 {
  DEFINES += cimg_display=2
 }
 
-linux {
+!macx {
   DEFINES += _IS_LINUX_
   PKGCONFIG += x11
   message( Linux platform )
