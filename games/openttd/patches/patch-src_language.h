$NetBSD: patch-src_language.h,v 1.1 2018/07/07 11:57:34 adam Exp $

Fix for ICU 61.
https://github.com/OpenTTD/OpenTTD/issues/6690

--- src/language.h.orig	2018-07-07 11:12:28.000000000 +0000
+++ src/language.h
@@ -105,7 +105,7 @@ extern LanguageList _languages;
 extern const LanguageMetadata *_current_language;
 
 #ifdef WITH_ICU_SORT
-extern Collator *_current_collator;
+extern icu::Collator *_current_collator;
 #endif /* WITH_ICU_SORT */
 
 bool ReadLanguagePack(const LanguageMetadata *lang);
