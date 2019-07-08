$NetBSD: patch-src_util_screensaver.cpp,v 1.1 2019/07/08 16:46:32 nia Exp $

Reuse the Linux code for other platforms.

--- src/util/screensaver.cpp.orig	2019-04-22 07:50:04.000000000 +0000
+++ src/util/screensaver.cpp
@@ -23,13 +23,13 @@ https://github.com/awjackson/bsnes-class
 #  include "util/mac.h"
 #elif defined(Q_OS_WIN)
 #  include <windows.h>
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
 #  include <QtDBus>
 #elif HAVE_XSCREENSAVER_SUSPEND
 #  include <X11/extensions/scrnsaver.h>
 #endif // Q_OS_WIN
 
-#if defined(Q_OS_LINUX) || HAVE_XSCREENSAVER_SUSPEND
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD) || HAVE_XSCREENSAVER_SUSPEND
 #  define None XNone
 #  define Window XWindow
 #  include <X11/Xlib.h>
@@ -140,7 +140,7 @@ void ScreenSaverHelper::uninhibitInterna
     s_enabled = false;
 }
 
-#elif defined(Q_OS_LINUX)
+#elif defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
 const char *SCREENSAVERS[][4] = {
     // org.freedesktop.ScreenSaver is the standard. should work for gnome and kde too, 
     // but I add their specific names too
