$NetBSD: patch-featherpad_singleton.cpp,v 1.1 2020/02/13 03:12:18 gutteridge Exp $

Allow building on NetBSD

--- featherpad/singleton.cpp.orig	2019-12-26 23:10:16.000000000 +0000
+++ featherpad/singleton.cpp
@@ -24,12 +24,12 @@
 #include <QCryptographicHash>
 #include <QThread>
 
-#if defined Q_OS_LINUX || defined Q_OS_FREEBSD || defined Q_OS_OPENBSD || defined Q_OS_HURD
+#if defined Q_OS_LINUX || defined Q_OS_FREEBSD || defined Q_OS_OPENBSD || defined Q_OS_NETBSD || defined Q_OS_HURD
 #include <unistd.h> // for geteuid()
 #endif
 
 #ifdef HAS_X11
-#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD || defined Q_OS_OPENBSD || defined Q_OS_HURD
+#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD || defined Q_OS_OPENBSD || defined Q_OS_NETBSD || defined Q_OS_HURD
 #include <QX11Info>
 #endif
 #endif
@@ -46,7 +46,7 @@ FPsingleton::FPsingleton (int &argc, cha
 {
 #ifdef HAS_X11
     // For now, the lack of x11 is seen as wayland.
-#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD || defined Q_OS_OPENBSD || defined Q_OS_HURD
+#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD || defined Q_OS_OPENBSD || defined Q_OS_NETBSD || defined Q_OS_HURD
     isX11_ = QX11Info::isPlatformX11();
 #else
     isX11_ = false;
@@ -278,7 +278,7 @@ FPwin* FPsingleton::newWin (const QStrin
     fp->show();
     if (socketFailure_)
         fp->showCrashWarning();
-#if defined Q_OS_LINUX || defined Q_OS_FREEBSD || defined Q_OS_OPENBSD || defined Q_OS_HURD
+#if defined Q_OS_LINUX || defined Q_OS_FREEBSD || defined Q_OS_OPENBSD || defined Q_OS_NETBSD || defined Q_OS_HURD
     else if (geteuid() == 0)
         fp->showRootWarning();
 #endif
