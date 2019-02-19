$NetBSD: patch-i18nutil_source_utility_unicode.cxx,v 1.4 2019/02/19 16:28:03 ryoon Exp $

add missing ICU namespace needed for icu 61.

--- i18nutil/source/utility/unicode.cxx.orig	2019-01-23 19:35:25.000000000 +0000
+++ i18nutil/source/utility/unicode.cxx
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
 static T getScriptType( const sal_Unicode ch, const L* typeList, T unknownType ) {
