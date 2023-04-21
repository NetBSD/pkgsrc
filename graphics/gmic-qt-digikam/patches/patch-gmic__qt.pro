$NetBSD: patch-gmic__qt.pro,v 1.1 2023/04/21 09:09:31 wiz Exp $

Link against libX11 on everything except macOS which might not use X11.
https://github.com/c-koi/gmic-qt/pull/180

--- gmic_qt.pro.orig	2023-04-17 02:59:18.000000000 +0000
+++ gmic_qt.pro
@@ -179,7 +179,7 @@ win32 {
  DEFINES += cimg_display=2
 }
 
-linux {
+unix:!macx {
   DEFINES += _IS_LINUX_
   PKGCONFIG += x11
   message( Linux platform )
