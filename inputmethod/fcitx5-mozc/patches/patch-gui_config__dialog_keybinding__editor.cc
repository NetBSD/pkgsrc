$NetBSD: patch-gui_config__dialog_keybinding__editor.cc,v 1.1 2021/02/17 15:29:51 ryoon Exp $

* NetBSD support

--- gui/config_dialog/keybinding_editor.cc.orig	2021-02-15 03:48:53.000000000 +0000
+++ gui/config_dialog/keybinding_editor.cc
@@ -381,7 +381,7 @@ KeyBindingFilter::KeyState KeyBindingFil
       return Encode(result);
     }
   }
-#elif OS_LINUX
+#elif defined(OS_LINUX) || defined(OS_NETBSD)
   // The XKB defines three types of logical key code: "xkb::Hiragana",
   // "xkb::Katakana" and "xkb::Hiragana_Katakana".
   // On most of Linux distributions, any key event against physical
@@ -478,7 +478,7 @@ bool KeyBindingFilter::eventFilter(QObje
 KeyBindingEditor::KeyBindingEditor(QWidget *parent, QWidget *trigger_parent)
     : QDialog(parent), trigger_parent_(trigger_parent) {
   setupUi(this);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   // Workaround for the issue https://github.com/google/mozc/issues/9
   // Seems that even after clicking the button for the keybinding dialog,
   // the edit is not raised. This might be a bug of setFocusProxy.
