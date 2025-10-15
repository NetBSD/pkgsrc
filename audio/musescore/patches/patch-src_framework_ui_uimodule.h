$NetBSD: patch-src_framework_ui_uimodule.h,v 1.1 2025/10/15 01:32:01 gutteridge Exp $

Provide a usable context for NetBSD.

--- src/framework/ui/uimodule.h.orig	2025-10-10 09:21:06.000000000 +0000
+++ src/framework/ui/uimodule.h
@@ -38,7 +38,7 @@ class WindowsController;
 class MacOSPlatformTheme;
 #elif defined(Q_OS_WIN)
 class WindowsPlatformTheme;
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
 class LinuxPlatformTheme;
 #else
 class StubPlatformTheme;
@@ -71,7 +71,7 @@ private:
     std::shared_ptr<MacOSPlatformTheme> m_platformTheme;
     #elif defined(Q_OS_WIN)
     std::shared_ptr<WindowsPlatformTheme> m_platformTheme;
-    #elif defined(Q_OS_LINUX)
+    #elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
     std::shared_ptr<LinuxPlatformTheme> m_platformTheme;
     #else
     std::shared_ptr<StubPlatformTheme> m_platformTheme;
