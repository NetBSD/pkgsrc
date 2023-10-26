$NetBSD: patch-Plugin_clPluginsFindBar.h,v 1.1 2023/10/26 10:46:58 nros Exp $

Missing declaration of wxStaticText

--- Plugin/clPluginsFindBar.h.orig	2023-10-22 11:38:56.024425430 +0000
+++ Plugin/clPluginsFindBar.h
@@ -33,6 +33,7 @@
 #include <codelite_exports.h>
 #include <wx/combobox.h>
 #include <wx/panel.h>
+#include <wx/stattext.h>
 
 class wxStyledTextCtrl;
 
