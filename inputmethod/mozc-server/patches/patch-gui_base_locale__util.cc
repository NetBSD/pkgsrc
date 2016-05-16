$NetBSD: patch-gui_base_locale__util.cc,v 1.3 2016/05/16 11:51:49 ryoon Exp $

--- gui/base/locale_util.cc.orig	2016-05-15 08:11:11.000000000 +0000
+++ gui/base/locale_util.cc
@@ -125,7 +125,7 @@ QString GetUILocaleName() {
 
   return result;
 #else  // OS_MACOSX
-  // return system locale on Linux
+  // return system locale on Linux or NetBSD
   return QLocale::system().name();
 #endif  // OS_LINUX
 }
@@ -204,7 +204,7 @@ TranslationDataImpl::TranslationDataImpl
   qApp->installEventFilter(&window_title_modifier_);
 #endif  // MOZC_SHOW_BUILD_NUMBER_ON_TITLE
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   // Use system default messages.
   // Even if the locale is not English nor Japanese, load translation
   // file to translate common messages like "OK" and "Cancel".
