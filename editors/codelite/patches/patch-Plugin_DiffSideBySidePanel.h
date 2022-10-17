$NetBSD: patch-Plugin_DiffSideBySidePanel.h,v 1.1 2022/10/17 16:50:03 andvar Exp $

Reorder <wx/filename.h> to fix build in NetBSD.

--- Plugin/DiffSideBySidePanel.h.orig	2022-04-18 08:09:00.000000000 +0300
+++ Plugin/DiffSideBySidePanel.h
@@ -26,13 +26,15 @@
 #ifndef DIFFSIDEBYSIDEPANEL_H
 #define DIFFSIDEBYSIDEPANEL_H
 
+#include <wx/filename.h>
+
+#include "wxcrafter_plugin.h"
 #include "DiffConfig.h"
 #include "clDTL.h"
 #include "clPluginsFindBar.h"
 #include "wxcrafter_plugin.h"
 
 #include <vector>
-#include <wx/filename.h>
 
 class clToolBar;
 class WXDLLIMPEXP_SDK DiffSideBySidePanel : public DiffSideBySidePanelBase
