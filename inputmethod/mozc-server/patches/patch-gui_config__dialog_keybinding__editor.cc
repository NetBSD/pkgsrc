$NetBSD: patch-gui_config__dialog_keybinding__editor.cc,v 1.1 2013/04/29 09:52:17 ryoon Exp $

--- gui/config_dialog/keybinding_editor.cc.orig	2012-08-31 05:37:09.000000000 +0000
+++ gui/config_dialog/keybinding_editor.cc
@@ -33,7 +33,7 @@
 #include <windows.h>
 #include <imm.h>
 #include <ime.h>
-#elif OS_LINUX
+#elif defined(OS_LINUX) || defined(OS_NETBSD)
 #define XK_MISCELLANY
 #include <X11/keysymdef.h>
 #endif
@@ -121,7 +121,7 @@ const WinVirtualKeyEntry kWinVirtualKeyM
   { VK_DBE_DBCSCHAR, "Hankaku/Zenkaku" },        // Zenkaku/hankaku
   // { VK_KANJI, "Kanji" },  // Do not support Kanji
 };
-#elif OS_LINUX
+#elif defined(OS_LINUX) || defined(OS_NETBSD)
 struct LinuxVirtualKeyEntry {
   uint16 virtual_key;
   const char *mozc_key_name;
@@ -390,7 +390,7 @@ KeyBindingFilter::KeyState KeyBindingFil
       return Encode(result);
     }
   }
-#elif OS_LINUX
+#elif defined(OS_LINUX) || defined(OS_NETBSD)
   const uint16 virtual_key = key_event.nativeVirtualKey();
 
   // The XKB defines three types of logical key code: "xkb::Hiragana",
@@ -500,7 +500,7 @@ bool KeyBindingFilter::eventFilter(QObje
 KeyBindingEditor::KeyBindingEditor(QWidget *parent, QWidget *trigger_parent)
     : QDialog(parent), trigger_parent_(trigger_parent) {
   setupUi(this);
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   // Workaround for the issue http://code.google.com/p/mozc/issues/detail?id=9
   // Seems that even after clicking the button for the keybinding dialog,
   // the edit is not raised. This might be a bug of setFocusProxy.
