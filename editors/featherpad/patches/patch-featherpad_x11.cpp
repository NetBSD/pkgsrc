$NetBSD: patch-featherpad_x11.cpp,v 1.1 2020/02/13 03:12:18 gutteridge Exp $

Allow building on NetBSD

--- featherpad/x11.cpp.orig	2019-12-26 23:10:16.000000000 +0000
+++ featherpad/x11.cpp
@@ -20,7 +20,7 @@
 #include <QString>
 #include "x11.h"
 
-#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD || defined Q_OS_OPENBSD || defined Q_OS_HURD
+#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD || defined Q_OS_OPENBSD || defined Q_OS_NETBSD || defined Q_OS_HURD
 #include <X11/Xatom.h>
 #include <QX11Info>
 #endif
@@ -37,7 +37,7 @@ long fromDesktop()
 {
     long res = -1;
 
-#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD || defined Q_OS_OPENBSD || defined Q_OS_HURD
+#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD || defined Q_OS_OPENBSD || defined Q_OS_NETBSD || defined Q_OS_HURD
     Display  *disp = QX11Info::display();
     if (!disp) return res;
 
@@ -72,7 +72,7 @@ long onWhichDesktop (Window window)
 {
     long res = -1;
 
-#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD || defined Q_OS_OPENBSD || defined Q_OS_HURD
+#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD || defined Q_OS_OPENBSD || defined Q_OS_NETBSD || defined Q_OS_HURD
     Display *disp = QX11Info::display();
     if (!disp) return res;
 
@@ -107,7 +107,7 @@ long onWhichDesktop (Window window)
 
 bool isWindowShaded (Window window)
 {
-#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD || defined Q_OS_OPENBSD || defined Q_OS_HURD
+#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD || defined Q_OS_OPENBSD || defined Q_OS_NETBSD || defined Q_OS_HURD
     Display *disp = QX11Info::display();
     if (!disp) return false;
 
@@ -142,7 +142,7 @@ bool isWindowShaded (Window window)
 /*************************/
 void unshadeWindow (Window window)
 {
-#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD || defined Q_OS_OPENBSD || defined Q_OS_HURD
+#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD || defined Q_OS_OPENBSD || defined Q_OS_NETBSD || defined Q_OS_HURD
     Display *disp = QX11Info::display();
     if (!disp) return;
 
