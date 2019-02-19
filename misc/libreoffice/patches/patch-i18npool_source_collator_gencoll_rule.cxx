$NetBSD: patch-i18npool_source_collator_gencoll_rule.cxx,v 1.2 2019/02/19 16:28:03 ryoon Exp $

add missing ICU namespace needed for icu 61.

--- i18npool/source/collator/gencoll_rule.cxx.orig	2019-01-23 19:35:25.000000000 +0000
+++ i18npool/source/collator/gencoll_rule.cxx
@@ -31,6 +31,8 @@
 
 #include <unicode/tblcoll.h>
 
+using namespace U_ICU_NAMESPACE;
+
 /* Main Procedure */
 
 static void data_write(char* file, char* name, sal_uInt8 *data, sal_Int32 len)
