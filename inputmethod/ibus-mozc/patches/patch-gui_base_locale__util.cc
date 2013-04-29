$NetBSD: patch-gui_base_locale__util.cc,v 1.2 2013/04/29 09:21:24 ryoon Exp $

--- gui/base/locale_util.cc.orig	2013-03-29 04:34:04.000000000 +0000
+++ gui/base/locale_util.cc
@@ -207,7 +207,7 @@ TranslationDataImpl::TranslationDataImpl
   qApp->installEventFilter(&window_title_modifier_);
 #endif  // MOZC_SHOW_BUILD_NUMBER_ON_TITLE
 
-#ifdef OS_LINUX
+#if defined(OS_LINUX) || defined(OS_NETBSD)
   // Use system default messages.
   // Even if the locale is not English nor Japanese, load translation
   // file to translate common messages like "OK" and "Cancel".
