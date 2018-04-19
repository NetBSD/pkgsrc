$NetBSD: patch-i18npool_source_collator_collator_unicode.cxx,v 1.1 2018/04/19 18:07:03 mrg Exp $

add missing ICU namespace needed for icu 61.

--- i18npool/source/collator/collator_unicode.cxx.orig	2018-03-29 08:04:09.000000000 -0700
+++ i18npool/source/collator/collator_unicode.cxx	2018-04-17 19:05:09.376978924 -0700
@@ -33,6 +33,7 @@
 using namespace ::com::sun::star::i18n;
 using namespace ::com::sun::star::lang;
 using namespace ::com::sun::star::uno;
+using namespace U_ICU_NAMESPACE;
 
 namespace i18npool {
 
