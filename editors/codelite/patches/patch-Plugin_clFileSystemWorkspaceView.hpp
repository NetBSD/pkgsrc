$NetBSD: patch-Plugin_clFileSystemWorkspaceView.hpp,v 1.1 2023/10/26 10:46:58 nros Exp $

Missing declaration of wxChoice

--- Plugin/clFileSystemWorkspaceView.hpp.orig	2023-01-11 21:18:07.000000000 +0000
+++ Plugin/clFileSystemWorkspaceView.hpp
@@ -7,6 +7,8 @@
 #include "cl_command_event.h"
 #include "cl_config.h"
 
+#include <wx/choice.h>
+
 class clThemedButton;
 class WXDLLIMPEXP_SDK clFileSystemWorkspaceView : public clTreeCtrlPanel
 {
