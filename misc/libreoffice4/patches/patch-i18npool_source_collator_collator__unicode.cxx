$NetBSD: patch-i18npool_source_collator_collator__unicode.cxx,v 1.1 2014/05/01 00:32:11 ryoon Exp $

* Fix icu53 build
  The concept is from http://cgit.freedesktop.org/libreoffice/core/commit/?id=2d843bb104a3091a2ff2c7b4d5655f5fb1393a47

--- i18npool/source/collator/collator_unicode.cxx.orig	2014-04-08 11:46:25.000000000 +0000
+++ i18npool/source/collator/collator_unicode.cxx
@@ -170,9 +170,11 @@ Collator_Unicode::loadCollatorAlgorithm(
                     func = get_collator_data_ja_phonetic_alphanumeric_first;
                 else if ( rAlgorithm == "phonetic (alphanumeric last)" )
                     func = get_collator_data_ja_phonetic_alphanumeric_last;
+#if 0
             } else if ( rLocale.Language == "ko" ) {
                 if ( rAlgorithm == "charset" )
                     func = get_collator_data_ko_charset;
+#endif
             } else if ( rLocale.Language == "ku" ) {
                 if ( rAlgorithm == "alphanumeric" )
                     func = get_collator_data_ku_alphanumeric;
