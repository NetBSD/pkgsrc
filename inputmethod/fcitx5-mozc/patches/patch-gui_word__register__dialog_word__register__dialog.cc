$NetBSD: patch-gui_word__register__dialog_word__register__dialog.cc,v 1.1 2021/02/17 15:29:51 ryoon Exp $

* NetBSD support
* Fix from https://github.com/google/mozc/issues/460

--- gui/word_register_dialog/word_register_dialog.cc.orig	2021-02-15 03:48:53.000000000 +0000
+++ gui/word_register_dialog/word_register_dialog.cc
@@ -97,9 +97,9 @@ QString GetEnv(const char *envname) {
   }
   return QLatin1String("");
 #endif  // OS_WIN
-#if defined(__APPLE__) || defined(OS_LINUX)
+#if defined(__APPLE__) || defined(OS_LINUX) || defined(OS_NETBSD)
   return QString::fromUtf8(::getenv(envname));
-#endif  // __APPLE__ or OS_LINUX
+#endif  // __APPLE__ or OS_LINUX or OS_NETBSD
   // TODO(team): Support other platforms.
   return QLatin1String("");
 }
