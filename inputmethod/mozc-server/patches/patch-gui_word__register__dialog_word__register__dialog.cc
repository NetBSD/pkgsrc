$NetBSD: patch-gui_word__register__dialog_word__register__dialog.cc,v 1.5 2020/06/19 05:45:30 taca Exp $

* NetBSD support
* Fix from https://github.com/google/mozc/issues/460

--- gui/word_register_dialog/word_register_dialog.cc.orig	2017-11-02 13:32:47.000000000 +0000
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
@@ -301,7 +301,7 @@ WordRegisterDialog::ErrorCode WordRegist
   }
 
   UserDictionary *dic =
-      session_->mutable_storage()->mutable_dictionaries(index);
+      session_->mutable_storage()->user_dictionary_storage_base.mutable_dictionaries(index);
   CHECK(dic);
 
   if (dic->name() != DictionarycomboBox->currentText().toStdString()) {
