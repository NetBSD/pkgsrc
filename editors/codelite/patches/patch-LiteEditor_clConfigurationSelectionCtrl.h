$NetBSD: patch-LiteEditor_clConfigurationSelectionCtrl.h,v 1.1 2023/10/26 10:46:58 nros Exp $

Missing declaration of wxChoice

--- LiteEditor/clConfigurationSelectionCtrl.h.orig	2023-01-11 21:18:07.000000000 +0000
+++ LiteEditor/clConfigurationSelectionCtrl.h
@@ -5,6 +5,7 @@
 #include "cl_command_event.h"
 
 #include <wx/arrstr.h>
+#include <wx/choice.h>
 #include <wx/panel.h>
 
 #define OPEN_CONFIG_MGR_STR _("Open Workspace Configuration Manager...")
