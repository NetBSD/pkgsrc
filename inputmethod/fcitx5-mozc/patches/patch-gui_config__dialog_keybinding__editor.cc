$NetBSD: patch-gui_config__dialog_keybinding__editor.cc,v 1.2 2024/02/10 12:26:02 ryoon Exp $

--- gui/config_dialog/keybinding_editor.cc.orig	2023-12-13 09:41:52.856716895 +0000
+++ gui/config_dialog/keybinding_editor.cc
@@ -111,7 +111,7 @@ static const auto *kQtKeyModifierNonRequ
         {Qt::Key_Hiragana_Katakana, "Hiragana"},
         {Qt::Key_Eisu_toggle, "Eisu"},
         {Qt::Key_Zenkaku_Hankaku, "Hankaku/Zenkaku"},
-#ifdef __linux__
+#if defined(__linux__) || defined(__NetBSD__)
         // On Linux (X / Wayland), Hangul and Hanja are identical with
         // ImeOn and ImeOff.
         // https://github.com/google/mozc/issues/552
@@ -361,7 +361,7 @@ KeyBindingFilter::KeyState KeyBindingFil
       return Encode(result);
     }
   }
-#elif __linux__
+#elif defined(__linux__) || defined(__NetBSD__)
   // The XKB defines three types of logical key code: "xkb::Hiragana",
   // "xkb::Katakana" and "xkb::Hiragana_Katakana".
   // On most of Linux distributions, any key event against physical
@@ -460,7 +460,7 @@ bool KeyBindingFilter::eventFilter(QObje
 KeyBindingEditor::KeyBindingEditor(QWidget *parent, QWidget *trigger_parent)
     : QDialog(parent), trigger_parent_(trigger_parent) {
   setupUi(this);
-#if defined(__linux__)
+#if defined(__linux__) || defined(__NetBSD__)
   // Workaround for the issue https://github.com/google/mozc/issues/9
   // Seems that even after clicking the button for the keybinding dialog,
   // the edit is not raised. This might be a bug of setFocusProxy.
