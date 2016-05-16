$NetBSD: patch-gui_config__dialog_keybinding__editor.cc,v 1.2 2016/05/16 11:51:49 ryoon Exp $

--- gui/config_dialog/keybinding_editor.cc.orig	2016-05-15 08:11:11.000000000 +0000
+++ gui/config_dialog/keybinding_editor.cc
@@ -37,7 +37,7 @@
 #include <windows.h>
 #include <imm.h>
 #include <ime.h>
-#elif OS_LINUX
+#elif defined(OS_LINUX) || defined(OS_NETBSD)
 #define XK_MISCELLANY
 #include <X11/keysymdef.h>
 #endif
@@ -125,7 +125,7 @@ const WinVirtualKeyEntry kWinVirtualKeyM
   { VK_DBE_DBCSCHAR, "Hankaku/Zenkaku" },        // Zenkaku/hankaku
   // { VK_KANJI, "Kanji" },  // Do not support Kanji
 };
-#elif OS_LINUX
+#elif defined(OS_LINUX) || defined(OS_NETBSD)
 struct LinuxVirtualKeyEntry {
   uint16 virtual_key;
   const char *mozc_key_name;
@@ -394,7 +394,7 @@ KeyBindingFilter::KeyState KeyBindingFil
       return Encode(result);
     }
   }
-#elif OS_LINUX
+#elif defined(OS_LINUX) || defined(OS_NETBSD)
   const uint16 virtual_key = key_event.nativeVirtualKey();
 
   // The XKB defines three types of logical key code: "xkb::Hiragana",
@@ -504,7 +504,7 @@ bool KeyBindingFilter::eventFilter(QObje
 KeyBindingEditor::KeyBindingEditor(QWidget *parent, QWidget *trigger_parent)
     : QDialog(parent), trigger_parent_(trigger_parent) {
   setupUi(this);
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   // Workaround for the issue https://github.com/google/mozc/issues/9
   // Seems that even after clicking the button for the keybinding dialog,
   // the edit is not raised. This might be a bug of setFocusProxy.
