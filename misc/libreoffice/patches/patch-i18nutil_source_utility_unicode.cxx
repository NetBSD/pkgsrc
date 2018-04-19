$NetBSD: patch-i18nutil_source_utility_unicode.cxx,v 1.3 2018/04/19 18:07:03 mrg Exp $

add missing ICU namespace needed for icu 61.

--- i18nutil/source/utility/unicode.cxx.orig	2018-03-29 08:04:09.000000000 -0700
+++ i18nutil/source/utility/unicode.cxx	2018-04-17 18:01:19.268575308 -0700
@@ -25,6 +25,7 @@
 #include <i18nutil/unicode.hxx>
 #include <sal/log.hxx>
 #include <unicode/numfmt.h>
+#include <unicode/regex.h>
 #include "unicode_data.h"
 #include <rtl/character.hxx>
 #include <memory>
@@ -35,6 +36,7 @@
 #undef CURRENCY_SYMBOL
 
 using namespace ::com::sun::star::i18n;
+using namespace U_ICU_NAMESPACE;
 
 template<class L, typename T>
 T getScriptType( const sal_Unicode ch, const L* typeList, T unknownType ) {
