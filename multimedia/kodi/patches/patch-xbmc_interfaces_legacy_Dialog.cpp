$NetBSD: patch-xbmc_interfaces_legacy_Dialog.cpp,v 1.1 2015/12/23 12:43:25 joerg Exp $

--- xbmc/interfaces/legacy/Dialog.cpp.orig	2015-12-22 18:00:09.000000000 +0000
+++ xbmc/interfaces/legacy/Dialog.cpp
@@ -33,6 +33,7 @@
 #include "WindowException.h"
 #include "ApplicationMessenger.h"
 #include "Dialog.h"
+#include <cstdlib>
 
 #define ACTIVE_WINDOW g_windowManager.GetActiveWindow()
 
