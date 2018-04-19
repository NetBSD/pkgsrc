$NetBSD: patch-i18npool_source_transliteration_ignoreDiacritics_CTL.cxx,v 1.1 2018/04/19 18:07:03 mrg Exp $

add missing ICU namespace needed for icu 61.

--- i18npool/source/transliteration/ignoreDiacritics_CTL.cxx.orig	2018-03-29 08:04:09.000000000 -0700
+++ i18npool/source/transliteration/ignoreDiacritics_CTL.cxx	2018-04-18 01:02:51.940106962 -0700
@@ -12,6 +12,8 @@
 #include <unicode/translit.h>
 #include <unicode/uchar.h>
 
+using namespace U_ICU_NAMESPACE;
+
 namespace i18npool {
 
 ignoreDiacritics_CTL::ignoreDiacritics_CTL()
