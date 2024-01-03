$NetBSD: patch-LiteEditor_editorsettingsdockingwidows.cpp,v 1.1 2024/01/03 13:30:49 nros Exp $

* Fix, error call of overloaded ... is ambiguous
  taken from upstream:
  https://github.com/eranif/codelite/commit/c5c975afa30c958b87399255abf13e653138a697

--- LiteEditor/editorsettingsdockingwidows.cpp.orig	2024-01-03 13:11:10.864486752 +0000
+++ LiteEditor/editorsettingsdockingwidows.cpp
@@ -59,7 +59,7 @@ EditorSettingsDockingWindows::EditorSett
     std::unordered_map<wxString, wxDirection> orientation_map = { { "UP", wxUP }, { "DOWN", wxDOWN } };
     std::unordered_map<int, wxString> orientation_map_reverse = { { wxUP, "UP" }, { wxDOWN, "DOWN" } };
 
-    AddProperty(_("Workspace tabs orientation"), { "UP", "DOWN" },
+    AddProperty(_("Workspace tabs orientation"), std::vector<wxString>{ "UP", "DOWN" },
                 orientation_map_reverse[m_options->GetWorkspaceTabsDirection()],
                 [this, orientation_map](const wxString&, const wxAny& value) mutable {
                     wxString str_value;
@@ -67,7 +67,7 @@ EditorSettingsDockingWindows::EditorSett
                         m_options->SetWorkspaceTabsDirection(orientation_map[str_value]);
                     }
                 });
-    AddProperty(_("Output tabs orientation"), { "UP", "DOWN" },
+    AddProperty(_("Output tabs orientation"), std::vector<wxString>{ "UP", "DOWN" },
                 orientation_map_reverse[m_options->GetOutputTabsDirection()],
                 [this, orientation_map](const wxString&, const wxAny& value) mutable {
                     wxString str_value;
