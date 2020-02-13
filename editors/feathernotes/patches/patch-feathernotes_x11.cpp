$NetBSD: patch-feathernotes_x11.cpp,v 1.1 2020/02/13 03:21:54 gutteridge Exp $

Define NetBSD

--- feathernotes/x11.cpp.orig	2020-01-06 06:05:04.000000000 +0000
+++ feathernotes/x11.cpp
@@ -18,7 +18,7 @@
 #include <QString>
 #include "x11.h"
 
-#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_OPENBSD || defined Q_OS_HURD
+#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_OPENBSD || defined Q_OS_NETBSD || defined Q_OS_HURD
 #include <X11/Xatom.h>
 #include <QX11Info>
 #endif
@@ -35,7 +35,7 @@ long fromDesktop()
 {
     long res = -1;
 
-#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_OPENBSD || defined Q_OS_HURD
+#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_OPENBSD || defined Q_OS_NETBSD || defined Q_OS_HURD
     Display  *disp = QX11Info::display();
     if (!disp) return res;
 
@@ -70,7 +70,7 @@ long onWhichDesktop (Window w)
 {
     long res = -1;
 
-#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_OPENBSD || defined Q_OS_HURD
+#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_OPENBSD || defined Q_OS_NETBSD || defined Q_OS_HURD
     Display *disp = QX11Info::display();
     if (!disp) return res;
 
@@ -102,7 +102,7 @@ long onWhichDesktop (Window w)
 // which was defined in gdkwindow-x11.c.
 void moveToCurrentDesktop (Window w)
 {
-#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_OPENBSD || defined Q_OS_HURD
+#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_OPENBSD || defined Q_OS_NETBSD || defined Q_OS_HURD
     Display *disp = QX11Info::display();
     if (!disp) return;
 
