$NetBSD: patch-gui_word__register__dialog_word__register__dialog.cc,v 1.2 2013/04/29 09:21:24 ryoon Exp $

--- gui/word_register_dialog/word_register_dialog.cc.orig	2013-03-29 04:34:02.000000000 +0000
+++ gui/word_register_dialog/word_register_dialog.cc
@@ -82,7 +82,7 @@ QString GetEnv(const char *envname) {
   }
   return "";
 #endif  // OS_WIN
-#if defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_NETBSD)
   return ::getenv(envname);
 #endif  // OS_MACOSX or OS_LINUX
   // TODO(team): Support other platforms.
