$NetBSD: patch-xbmc_windowing_WinEvents.cpp,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/windowing/WinEvents.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/windowing/WinEvents.cpp
@@ -38,11 +38,11 @@
 #include "android/WinEventsAndroid.h"
 #define WinEventsType CWinEventsAndroid
 
-#elif (defined(TARGET_FREEBSD) || defined(TARGET_LINUX)) && defined(HAS_SDL_WIN_EVENTS)
+#elif (defined(TARGET_FREEBSD) || defined(TARGET_NETBSD) || defined(TARGET_LINUX)) && defined(HAS_SDL_WIN_EVENTS)
 #include "WinEventsSDL.h"
 #define WinEventsType CWinEventsSDL
 
-#elif (defined(TARGET_FREEBSD) || defined(TARGET_LINUX)) && defined(HAS_X11_WIN_EVENTS)
+#elif (defined(TARGET_FREEBSD) || defined(TARGET_NETBSD) || defined(TARGET_LINUX)) && defined(HAS_X11_WIN_EVENTS)
 #include "WinEventsX11.h"
 #define WinEventsType CWinEventsX11
 
