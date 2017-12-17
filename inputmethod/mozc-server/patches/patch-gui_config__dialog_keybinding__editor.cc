$NetBSD: patch-gui_config__dialog_keybinding__editor.cc,v 1.3 2017/12/17 14:15:43 tsutsui Exp $

* NetBSD support

--- gui/config_dialog/keybinding_editor.cc.orig	2017-11-02 13:32:47.000000000 +0000
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
@@ -128,7 +128,7 @@ const WinVirtualKeyEntry kWinVirtualKeyM
   { VK_DBE_DBCSCHAR, "Hankaku/Zenkaku" },        // Zenkaku/hankaku
   // { VK_KANJI, "Kanji" },  // Do not support Kanji
 };
-#elif OS_LINUX
+#elif defined(OS_LINUX) || defined(OS_NETBSD)
 struct LinuxVirtualKeyEntry {
   uint16 virtual_key;
   const char *mozc_key_name;
@@ -397,7 +397,7 @@ KeyBindingFilter::KeyState KeyBindingFil
       return Encode(result);
     }
   }
-#elif OS_LINUX
+#elif defined(OS_LINUX) || defined(OS_NETBSD)
   const uint16 virtual_key = key_event.nativeVirtualKey();
 
   // The XKB defines three types of logical key code: "xkb::Hiragana",
@@ -507,7 +507,7 @@ bool KeyBindingFilter::eventFilter(QObje
 KeyBindingEditor::KeyBindingEditor(QWidget *parent, QWidget *trigger_parent)
     : QDialog(parent), trigger_parent_(trigger_parent) {
   setupUi(this);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   // Workaround for the issue https://github.com/google/mozc/issues/9
   // Seems that even after clicking the button for the keybinding dialog,
   // the edit is not raised. This might be a bug of setFocusProxy.
