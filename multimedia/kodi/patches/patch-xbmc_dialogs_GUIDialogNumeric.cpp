$NetBSD: patch-xbmc_dialogs_GUIDialogNumeric.cpp,v 1.1 2015/12/23 12:43:25 joerg Exp $

--- xbmc/dialogs/GUIDialogNumeric.cpp.orig	2015-12-22 17:57:34.000000000 +0000
+++ xbmc/dialogs/GUIDialogNumeric.cpp
@@ -28,6 +28,7 @@
 #include "input/Key.h"
 #include "guilib/LocalizeStrings.h"
 #include "interfaces/AnnouncementManager.h"
+#include <cstdlib>
 
 #define CONTROL_HEADING_LABEL  1
 #define CONTROL_INPUT_LABEL    4
