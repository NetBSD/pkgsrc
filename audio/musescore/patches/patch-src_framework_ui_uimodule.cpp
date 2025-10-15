$NetBSD: patch-src_framework_ui_uimodule.cpp,v 1.1 2025/10/15 01:32:01 gutteridge Exp $

Provide a usable context for NetBSD.

--- src/framework/ui/uimodule.cpp.orig	2025-10-10 09:21:06.000000000 +0000
+++ src/framework/ui/uimodule.cpp
@@ -43,7 +43,7 @@
 #include "internal/platform/windows/windowsplatformtheme.h"
 #include "internal/platform/windows/winwindowscontroller.h"
 #include "view/mainwindowbridge.h"
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
 #include "internal/platform/linux/linuxplatformtheme.h"
 #include "internal/windowscontroller.h"
 #include "view/mainwindowbridge.h"
@@ -104,7 +104,7 @@ void UiModule::registerExports()
     #elif defined(Q_OS_WIN)
     m_platformTheme = std::make_shared<WindowsPlatformTheme>();
     m_windowsController = std::make_shared<WinWindowsController>();
-    #elif defined(Q_OS_LINUX)
+    #elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
     m_platformTheme = std::make_shared<LinuxPlatformTheme>();
     m_windowsController = std::make_shared<WindowsController>();
     #else
@@ -120,6 +120,7 @@ void UiModule::registerExports()
     ioc()->registerExport<IUiActionsRegister>(moduleName(), m_uiactionsRegister);
     ioc()->registerExport<INavigationController>(moduleName(), m_keyNavigationController);
     ioc()->registerExport<IDragController>(moduleName(), new DragController());
+    // XXX this will fail with the #else above, as m_windowsController is not defined!
     ioc()->registerExport<IWindowsController>(moduleName(), m_windowsController);
 }
 
