$NetBSD: patch-gui_word__register__dialog_word__register__dialog.cc,v 1.3 2016/05/16 11:51:49 ryoon Exp $

--- gui/word_register_dialog/word_register_dialog.cc.orig	2016-05-15 08:11:11.000000000 +0000
+++ gui/word_register_dialog/word_register_dialog.cc
@@ -90,9 +90,9 @@ QString GetEnv(const char *envname) {
   }
   return "";
 #endif  // OS_WIN
-#if defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_NETBSD)
   return ::getenv(envname);
-#endif  // OS_MACOSX or OS_LINUX
+#endif  // OS_MACOSX, OS_LINUX or OS_NETBSD
   // TODO(team): Support other platforms.
   return "";
 }
