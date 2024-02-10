$NetBSD: patch-gui_config__dialog_keymap__editor.cc,v 1.1 2024/02/10 02:20:18 ryoon Exp $

--- gui/config_dialog/keymap_editor.cc.orig	2023-12-13 09:38:10.376387232 +0000
+++ gui/config_dialog/keymap_editor.cc
@@ -441,7 +441,7 @@ bool KeyMapEditorDialog::Update() {
   absl::StrAppend(keymap_table, invisible_keymap_table_);
 
   if (new_direct_mode_commands != direct_mode_commands_) {
-#if defined(_WIN32) || defined(__linux__)
+#if defined(_WIN32) || defined(__linux__) || defined(__NetBSD__)
     QMessageBox::information(
         this, windowTitle(),
         tr("Changes of keymaps for direct input mode will apply only to "
