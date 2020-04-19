$NetBSD: patch-style_themeconfig_ThemeConfig.cpp,v 1.1 2020/04/19 11:57:23 pin Exp $

Allow build on NetBSD

--- style/themeconfig/ThemeConfig.cpp.orig	2020-03-30 23:07:24.000000000 +0000
+++ style/themeconfig/ThemeConfig.cpp
@@ -19,7 +19,7 @@
 #include <QFile>
 #include <QApplication>
 #include "ThemeConfig.h"
-#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD || defined Q_OS_HURD
+#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD || defined Q_OS_NETBSD || defined Q_OS_HURD
 #include <QX11Info>
 #if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
 #include <X11/Xlib.h>
@@ -37,7 +37,7 @@ ThemeConfig::ThemeConfig(const QString& 
 {
   /* For now, the lack of x11 means wayland.
      Later, a better method should be found. */
-#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD || defined Q_OS_HURD
+#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD || defined Q_OS_NETBSD || defined Q_OS_HURD
 #if (QT_VERSION >= QT_VERSION_CHECK(5,2,0))
   isX11_ = QX11Info::isPlatformX11();
 #else
@@ -570,7 +570,7 @@ theme_spec ThemeConfig::getCompositeSpec
 {
   bool compositing(false);
 
-#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD || defined Q_OS_HURD
+#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD || defined Q_OS_NETBSD || defined Q_OS_HURD
   /* set to false if no compositing manager is running */
 #if (QT_VERSION >= QT_VERSION_CHECK(5,2,0))
   if (isX11_)
