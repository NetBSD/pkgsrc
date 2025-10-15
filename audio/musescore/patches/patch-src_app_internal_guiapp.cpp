$NetBSD: patch-src_app_internal_guiapp.cpp,v 1.1 2025/10/15 01:32:01 gutteridge Exp $

Treat NetBSD like FreeBSD.

--- src/app/internal/guiapp.cpp.orig	2025-10-10 09:21:06.000000000 +0000
+++ src/app/internal/guiapp.cpp
@@ -191,7 +191,7 @@ void GuiApp::perform()
     const QString mainQmlFile = "/platform/mac/Main.qml";
 #elif defined(Q_OS_WIN)
     const QString mainQmlFile = "/platform/win/Main.qml";
-#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
     const QString mainQmlFile = "/platform/linux/Main.qml";
 #endif
 
