$NetBSD: patch-gui_word__register__dialog_word__register__dialog.cc,v 1.2 2013/07/20 04:34:53 ryoon Exp $

--- gui/word_register_dialog/word_register_dialog.cc.orig	2013-07-17 02:38:14.000000000 +0000
+++ gui/word_register_dialog/word_register_dialog.cc
@@ -81,9 +81,9 @@ QString GetEnv(const char *envname) {
   }
   return "";
 #endif  // OS_WIN
-#if defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_NETBSD)
   return ::getenv(envname);
-#endif  // OS_MACOSX or OS_LINUX
+#endif  // OS_MACOSX or OS_LINUX or OS_NETBSD
   // TODO(team): Support other platforms.
   return "";
 }
