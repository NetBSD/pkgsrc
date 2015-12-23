$NetBSD: patch-xbmc_windowing_WinEventsX11.cpp,v 1.1 2015/12/23 12:43:25 joerg Exp $

--- xbmc/windowing/WinEventsX11.cpp.orig	2015-12-22 18:16:12.000000000 +0000
+++ xbmc/windowing/WinEventsX11.cpp
@@ -19,6 +19,8 @@
 *
 */
 
+#include <locale.h>
+#include <cstdlib>
 #include "system.h"
 
 #ifdef HAS_X11_WIN_EVENTS
