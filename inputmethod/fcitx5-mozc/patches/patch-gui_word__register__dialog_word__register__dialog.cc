$NetBSD: patch-gui_word__register__dialog_word__register__dialog.cc,v 1.2 2024/02/10 12:26:02 ryoon Exp $

--- gui/word_register_dialog/word_register_dialog.cc.orig	2023-12-13 09:33:09.127301725 +0000
+++ gui/word_register_dialog/word_register_dialog.cc
@@ -100,7 +100,7 @@ QString GetEnv(const char *envname) {
   }
   return QLatin1String("");
 #endif  // _WIN32
-#if defined(__APPLE__) || defined(__linux__)
+#if defined(__APPLE__) || defined(__linux__) || defined(__NetBSD__)
   return QString::fromUtf8(::getenv(envname));
 #endif  // __APPLE__ or __linux__
   // TODO(team): Support other platforms.
