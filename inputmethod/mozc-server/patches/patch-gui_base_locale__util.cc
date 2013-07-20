$NetBSD: patch-gui_base_locale__util.cc,v 1.2 2013/07/20 04:34:53 ryoon Exp $

--- gui/base/locale_util.cc.orig	2013-07-17 02:38:10.000000000 +0000
+++ gui/base/locale_util.cc
@@ -121,9 +121,9 @@ QString GetUILocaleName() {
 
   return result;
 #else  // OS_MACOSX
-  // return system locale on Linux
+  // return system locale on Linux or NetBSD
   return QLocale::system().name();
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_NETBSD
 }
 
 // sicnce Qtranslator and QFont must be available until
@@ -206,7 +206,7 @@ TranslationDataImpl::TranslationDataImpl
   qApp->installEventFilter(&window_title_modifier_);
 #endif  // MOZC_SHOW_BUILD_NUMBER_ON_TITLE
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   // Use system default messages.
   // Even if the locale is not English nor Japanese, load translation
   // file to translate common messages like "OK" and "Cancel".
