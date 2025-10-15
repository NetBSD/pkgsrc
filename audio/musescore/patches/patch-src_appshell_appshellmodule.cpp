$NetBSD: patch-src_appshell_appshellmodule.cpp,v 1.1 2025/10/15 01:32:01 gutteridge Exp $

Treat NetBSD like FreeBSD.

--- src/appshell/appshellmodule.cpp.orig	2025-07-21 11:28:07.334914966 +0000
+++ src/appshell/appshellmodule.cpp
@@ -157,7 +157,7 @@ void AppShellModule::registerUiTypes()
 
 #if defined(Q_OS_MACOS)
     qmlRegisterType<AppMenuModel>("MuseScore.AppShell", 1, 0, "PlatformAppMenuModel");
-#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
     qmlRegisterType<AppMenuModel>("MuseScore.AppShell", 1, 0, "PlatformAppMenuModel");
     qmlRegisterType<NavigableAppMenuModel>("MuseScore.AppShell", 1, 0, "AppMenuModel");
 #else
