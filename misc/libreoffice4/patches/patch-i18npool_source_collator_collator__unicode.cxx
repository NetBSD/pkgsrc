$NetBSD: patch-i18npool_source_collator_collator__unicode.cxx,v 1.2 2014/05/01 21:04:31 ryoon Exp $

* Fix icu53 build
  The concept is from http://cgit.freedesktop.org/libreoffice/core/commit/?id=2d843bb104a3091a2ff2c7b4d5655f5fb1393a47
* Follow icu53 API change
  http://cgit.freedesktop.org/libreoffice/core/commit/i18npool/source/collator/collator_unicode.cxx?id=a3c627fe38236e82bc6008075d862b3cbfbd9ce3

--- i18npool/source/collator/collator_unicode.cxx.orig	2014-04-08 11:46:25.000000000 +0000
+++ i18npool/source/collator/collator_unicode.cxx
@@ -120,6 +120,7 @@ Collator_Unicode::loadCollatorAlgorithm(
         }
         if (!collator && OUString::createFromAscii(LOCAL_RULE_LANGS).indexOf(rLocale.Language) >= 0) {
             const sal_uInt8* (*func)() = NULL;
+            size_t (*funclen)() = NULL;
 
 #ifndef DISABLE_DYNLOADING
             OUStringBuffer aBuf;
@@ -132,11 +133,21 @@ Collator_Unicode::loadCollatorAlgorithm(
                 aBuf.appendAscii("get_").append(rLocale.Language).appendAscii("_");
                 if ( rLocale.Language == "zh" ) {
                     OUString func_base = aBuf.makeStringAndClear();
+                    OUString funclen_base = func_base + "_length";
                     if (OUString("TW HK MO").indexOf(rLocale.Country) >= 0)
-                        func=(const sal_uInt8* (*)()) osl_getFunctionSymbol(hModule,
+                    {
+                        func = (const sal_uInt8* (*)()) osl_getFunctionSymbol(hModule,
                                     OUString(func_base + "TW_" + rAlgorithm).pData);
+                        funclen = (size_t (*)()) osl_getFunctionSymbol(hModule,
+                                    OUString(funclen_base + "TW_" + rAlgorithm).pData);
+                    }
                     if (!func)
-                        func=(const sal_uInt8* (*)()) osl_getFunctionSymbol(hModule, OUString(func_base + rAlgorithm).pData);
+                    {
+                        func = (const sal_uInt8* (*)()) osl_getFunctionSymbol(
+                                hModule, OUString(func_base + rAlgorithm).pData);
+                        funclen = (size_t (*)()) osl_getFunctionSymbol(
+                                hModule, OUString(funclen_base + rAlgorithm).pData);
+                    }
                 } else {
                     if ( rLocale.Language == "ja" ) {
                         // replace algorithm name to implementation name.
@@ -149,70 +160,147 @@ Collator_Unicode::loadCollatorAlgorithm(
                     } else {
                         aBuf.append(rAlgorithm);
                     }
-                    func=(const sal_uInt8* (*)()) osl_getFunctionSymbol(hModule, aBuf.makeStringAndClear().pData);
+                    OUString func_base = aBuf.makeStringAndClear();
+                    OUString funclen_base = func_base + "_length";
+                    func = (const sal_uInt8* (*)()) osl_getFunctionSymbol(hModule, func_base.pData);
+                    funclen = (size_t (*)()) osl_getFunctionSymbol(hModule, funclen_base.pData);
                 }
             }
 #else
             if ( rLocale.Language == "ca" ) {
                 if ( rAlgorithm == "charset" )
+                {
                     func = get_collator_data_ca_charset;
+                    funclen = get_collator_data_dz_charset_length;
+                }
             } else if ( rLocale.Language == "dz" || rLocale.Language == "bo" ) {
                 // 'bo' Tibetan uses the same collation rules as 'dz' Dzongkha
                 if ( rAlgorithm == "charset" )
+                {
                     func = get_collator_data_dz_charset;
+                    funclen = get_collator_data_dz_charset_length;
+                }
             } else if ( rLocale.Language == "hu" ) {
                 if ( rAlgorithm == "charset" )
+                {
                     func = get_collator_data_hu_charset;
+                    funclen = get_collator_data_hu_charset_length;
+                }
             } else if ( rLocale.Language == "ja" ) {
                 if ( rAlgorithm == "charset" )
+                {
                     func = get_collator_data_ja_charset;
+                    funclen = get_collator_data_ja_charset_length;
+                }
                 else if ( rAlgorithm == "phonetic (alphanumeric first)" )
+                {
                     func = get_collator_data_ja_phonetic_alphanumeric_first;
+                    funclen = get_collator_data_ja_phonetic_alphanumeric_first_length;
+                }
                 else if ( rAlgorithm == "phonetic (alphanumeric last)" )
+                {
                     func = get_collator_data_ja_phonetic_alphanumeric_last;
+                    funclen = get_collator_data_ja_phonetic_alphanumeric_last_length;
+                }
+#if 0
             } else if ( rLocale.Language == "ko" ) {
                 if ( rAlgorithm == "charset" )
+                {
                     func = get_collator_data_ko_charset;
+                    funclen = get_collator_data_ko_charset_length;
+                }
+#endif
             } else if ( rLocale.Language == "ku" ) {
                 if ( rAlgorithm == "alphanumeric" )
+                {
                     func = get_collator_data_ku_alphanumeric;
+                    funclen = get_collator_data_ku_alphanumeric_length;
+                }
             } else if ( rLocale.Language == "ln" ) {
                 if ( rAlgorithm == "charset" )
+                {
                     func = get_collator_data_ln_charset;
+                    funclen = get_collator_data_ln_charset_length;
+                }
             } else if ( rLocale.Language == "my" ) {
                 if ( rAlgorithm == "dictionary" )
+                {
                     func = get_collator_data_my_dictionary;
+                    funclen = get_collator_data_my_dictionary_length;
+                }
             } else if ( rLocale.Language == "ne" ) {
                 if ( rAlgorithm == "charset" )
+                {
                     func = get_collator_data_ne_charset;
+                    funclen = get_collator_data_ne_charset_length;
+                }
             } else if ( rLocale.Language == "sid" ) {
                 if ( rAlgorithm == "charset" )
+                {
                     func = get_collator_data_sid_charset;
+                    funclen = get_collator_data_sid_charset_length;
+                }
             } else if ( rLocale.Language == "zh" && (rLocale.Country == "TW" || rLocale.Country == "HK" || rLocale.Country == "MO") ) {
                 if ( rAlgorithm == "charset" )
+                {
                     func = get_collator_data_zh_TW_charset;
+                    funclen = get_collator_data_zh_TW_charset_length;
+                }
                 else if ( rAlgorithm == "radical" )
+                {
                     func = get_collator_data_zh_TW_radical;
+                    funclen = get_collator_data_zh_TW_radical_length;
+                }
                 else if ( rAlgorithm == "stroke" )
+                {
                     func = get_collator_data_zh_TW_stroke;
+                    funclen = get_collator_data_zh_TW_stroke_length;
+                }
             } else if ( rLocale.Language == "zh" ) {
                 if ( rAlgorithm == "charset" )
+                {
                     func = get_collator_data_zh_charset;
+                    funclen = get_collator_data_zh_charset_length;
+                }
                 else if ( rAlgorithm == "pinyin" )
+                {
                     func = get_collator_data_zh_pinyin;
+                    funclen = get_collator_data_zh_pinyin_length;
+                }
                 else if ( rAlgorithm == "radical" )
+                {
                     func = get_collator_data_zh_radical;
+                    funclen = get_collator_data_zh_radical_length;
+                }
                 else if ( rAlgorithm == "stroke" )
+                {
                     func = get_collator_data_zh_stroke;
+                    funclen = get_collator_data_zh_stroke_length;
+                }
                 else if ( rAlgorithm == "zhuyin" )
+                {
                     func = get_collator_data_zh_zhuyin;
+                    funclen = get_collator_data_zh_zhuyin_length;
+                }
             }
 #endif
-            if (func) {
+            if (func && funclen) {
                 const sal_uInt8* ruleImage=func();
-                uca_base = new RuleBasedCollator(static_cast<UChar*>(NULL), status);
+                size_t ruleImageSize = funclen();
+                // Not only changed ICU 53.1 the API behavior that a negative
+                // length (ruleImageSize) now leads to failure, but also that
+                // the base RuleBasedCollator passed as uca_base here needs to
+                // have a base->tailoring == CollationRoot::getRoot() otherwise
+                // the init bails out as well, as it does for the previously
+                // used "empty" RuleBasedCollator.
+                // The default collator of the en-US locale would also fulfill
+                // the requirement. The collator of the actual locale or the
+                // NULL (default) locale does not.
+                uca_base = static_cast<RuleBasedCollator*>(icu::Collator::createInstance(
+                icu::Locale::getRoot(), status));
                 if (! U_SUCCESS(status)) throw RuntimeException();
-                collator = new RuleBasedCollator(reinterpret_cast<const uint8_t*>(ruleImage), -1, uca_base, status);
+                collator = new RuleBasedCollator(
+                        reinterpret_cast<const uint8_t*>(ruleImage), ruleImageSize, uca_base, status);
                 if (! U_SUCCESS(status)) throw RuntimeException();
             }
         }
