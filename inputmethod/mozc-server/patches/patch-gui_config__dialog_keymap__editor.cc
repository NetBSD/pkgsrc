$NetBSD: patch-gui_config__dialog_keymap__editor.cc,v 1.2 2013/07/20 04:34:53 ryoon Exp $

--- gui/config_dialog/keymap_editor.cc.orig	2013-07-17 02:38:20.000000000 +0000
+++ gui/config_dialog/keymap_editor.cc
@@ -448,13 +448,13 @@ bool KeyMapEditorDialog::Update() {
   *keymap_table += invisible_keymap_table_;
 
   if (new_ime_switch_keymap != ime_switch_keymap_) {
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_NETBSD)
     QMessageBox::information(
         this,
         windowTitle(),
         tr("The keymaps for IME ON and Reconversion will be "
            "applied after new applications."));
-#endif  // OS_WIN || OS_LINUX
+#endif  // OS_WIN || OS_LINUX || OS_NETBSD
     ime_switch_keymap_ = new_ime_switch_keymap;
   }
 
