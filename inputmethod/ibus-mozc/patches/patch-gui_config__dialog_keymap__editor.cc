$NetBSD: patch-gui_config__dialog_keymap__editor.cc,v 1.2 2013/04/29 09:21:24 ryoon Exp $

--- gui/config_dialog/keymap_editor.cc.orig	2013-03-29 04:33:49.000000000 +0000
+++ gui/config_dialog/keymap_editor.cc
@@ -449,7 +449,7 @@ bool KeyMapEditorDialog::Update() {
   *keymap_table += invisible_keymap_table_;
 
   if (new_ime_switch_keymap != ime_switch_keymap_) {
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_NETBSD)
     QMessageBox::information(
         this,
         windowTitle(),
