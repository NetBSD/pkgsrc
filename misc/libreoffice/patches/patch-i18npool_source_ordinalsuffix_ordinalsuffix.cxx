$NetBSD: patch-i18npool_source_ordinalsuffix_ordinalsuffix.cxx,v 1.1 2018/04/19 18:07:03 mrg Exp $

add missing ICU namespace needed for icu 61.

--- i18npool/source/ordinalsuffix/ordinalsuffix.cxx.orig	2018-03-29 08:04:09.000000000 -0700
+++ i18npool/source/ordinalsuffix/ordinalsuffix.cxx	2018-04-17 18:02:13.070058714 -0700
@@ -32,6 +32,7 @@
 using namespace ::com::sun::star::i18n;
 using namespace ::com::sun::star::uno;
 using namespace ::com::sun::star;
+using namespace U_ICU_NAMESPACE;
 
 namespace i18npool {
 
