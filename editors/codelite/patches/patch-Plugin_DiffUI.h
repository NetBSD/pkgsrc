$NetBSD: patch-Plugin_DiffUI.h,v 1.1 2023/10/26 10:46:58 nros Exp $

Missing declaration of wxFrame

--- Plugin/DiffUI.h.orig	2023-01-11 21:18:07.000000000 +0000
+++ Plugin/DiffUI.h
@@ -15,6 +15,7 @@
 #include <wx/dataview.h>
 #include <wx/dialog.h>
 #include <wx/filepicker.h>
+#include <wx/frame.h>
 #include <wx/iconbndl.h>
 #include <wx/panel.h>
 #include <wx/settings.h>
