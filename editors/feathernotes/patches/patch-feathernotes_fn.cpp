$NetBSD: patch-feathernotes_fn.cpp,v 1.1 2020/02/13 03:21:54 gutteridge Exp $

Define NetBSD

--- feathernotes/fn.cpp.orig	2020-01-06 06:05:04.000000000 +0000
+++ feathernotes/fn.cpp
@@ -48,7 +48,7 @@
 #include <QMimeDatabase>
 
 #ifdef HAS_X11
-#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_OPENBSD || defined Q_OS_HURD
+#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_OPENBSD || defined Q_OS_NETBSD || defined Q_OS_HURD
 #include <QX11Info>
 #endif
 #include "x11.h"
@@ -65,7 +65,7 @@ FN::FN (const QString& message, QWidget 
 {
 #ifdef HAS_X11
     // For now, the lack of x11 is seen as wayland.
-#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD || defined Q_OS_OPENBSD || defined Q_OS_HURD
+#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD || defined Q_OS_OPENBSD || defined Q_OS_NETBSD ||  defined Q_OS_HURD
     isX11_ = QX11Info::isPlatformX11();
 #else
     isX11_ = false;
