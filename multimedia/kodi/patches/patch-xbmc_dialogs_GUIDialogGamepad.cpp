$NetBSD: patch-xbmc_dialogs_GUIDialogGamepad.cpp,v 1.1 2015/12/23 12:43:25 joerg Exp $

--- xbmc/dialogs/GUIDialogGamepad.cpp.orig	2015-12-22 17:55:50.000000000 +0000
+++ xbmc/dialogs/GUIDialogGamepad.cpp
@@ -26,6 +26,7 @@
 #include "GUIDialogOK.h"
 #include "input/Key.h"
 #include "guilib/LocalizeStrings.h"
+#include <cstdlib>
 
 CGUIDialogGamepad::CGUIDialogGamepad(void)
     : CGUIDialogBoxBase(WINDOW_DIALOG_GAMEPAD, "DialogGamepad.xml")
