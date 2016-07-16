$NetBSD: patch-src_preferences_dlg.cpp,v 1.1 2016/07/16 03:32:32 markd Exp $

Dont do things the old 2.6 way

--- src/preferences_dlg.cpp.orig	2012-06-28 06:39:35.000000000 +0000
+++ src/preferences_dlg.cpp
@@ -126,7 +126,7 @@ bool
 PreferencesDlg::SelectExecutable(const wxString & title, wxTextCtrl * textCtrl)
 {
   wxFileDialog dlg(this, title, wxEmptyString, wxEmptyString,
-                   EXECUTABLE_WILDCARD, wxOPEN);
+                   EXECUTABLE_WILDCARD, wxFD_OPEN);
   dlg.SetPath(textCtrl->GetValue());
 
   if (dlg.ShowModal() != wxID_OK)
