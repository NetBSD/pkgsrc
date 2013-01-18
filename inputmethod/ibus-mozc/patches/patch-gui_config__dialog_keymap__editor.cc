$NetBSD: patch-gui_config__dialog_keymap__editor.cc,v 1.1 2013/01/18 11:36:40 ryoon Exp $

--- gui/config_dialog/keymap_editor.cc.orig	2012-08-31 05:37:12.000000000 +0000
+++ gui/config_dialog/keymap_editor.cc
@@ -447,7 +447,7 @@ bool KeyMapEditorDialog::Update() {
   *keymap_table += invisible_keymap_table_;
 
   if (new_ime_switch_keymap != ime_switch_keymap_) {
-#if defined(OS_WINDOWS) || defined(OS_LINUX)
+#if defined(OS_WINDOWS) || defined(OS_LINUX) || defined(OS_NETBSD)
     QMessageBox::information(
         this,
         tr("Mozc settings"),
