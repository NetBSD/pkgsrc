$NetBSD: patch-src_strings.cpp,v 1.1 2018/07/07 11:57:34 adam Exp $

Fix for ICU 61.
https://github.com/OpenTTD/OpenTTD/issues/6690

--- src/strings.cpp.orig	2018-07-07 11:13:01.000000000 +0000
+++ src/strings.cpp
@@ -52,7 +52,7 @@ const LanguageMetadata *_current_languag
 TextDirection _current_text_dir; ///< Text direction of the currently selected language.
 
 #ifdef WITH_ICU_SORT
-Collator *_current_collator = NULL;               ///< Collator for the language currently in use.
+icu::Collator *_current_collator = NULL;          ///< Collator for the language currently in use.
 #endif /* WITH_ICU_SORT */
 
 static uint64 _global_string_params_data[20];     ///< Global array of string parameters. To access, use #SetDParam.
@@ -1795,7 +1795,7 @@ bool ReadLanguagePack(const LanguageMeta
 
 	/* Create a collator instance for our current locale. */
 	UErrorCode status = U_ZERO_ERROR;
-	_current_collator = Collator::createInstance(Locale(_current_language->isocode), status);
+	_current_collator = icu::Collator::createInstance(icu::Locale(_current_language->isocode), status);
 	/* Sort number substrings by their numerical value. */
 	if (_current_collator != NULL) _current_collator->setAttribute(UCOL_NUMERIC_COLLATION, UCOL_ON, status);
 	/* Avoid using the collator if it is not correctly set. */
