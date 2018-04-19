$NetBSD: patch-i18npool_source_collator_gencoll_rule.cxx,v 1.1 2018/04/19 18:07:03 mrg Exp $

add missing ICU namespace needed for icu 61.

--- i18npool/source/collator/gencoll_rule.cxx.orig	2018-03-29 08:04:09.000000000 -0700
+++ i18npool/source/collator/gencoll_rule.cxx	2018-04-18 03:21:55.610494602 -0700
@@ -31,6 +31,8 @@
 
 #include <unicode/tblcoll.h>
 
+using namespace U_ICU_NAMESPACE;
+
 /* Main Procedure */
 
 void data_write(char* file, char* name, sal_uInt8 *data, sal_Int32 len)
