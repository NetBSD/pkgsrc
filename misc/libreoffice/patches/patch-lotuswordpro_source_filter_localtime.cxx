$NetBSD: patch-lotuswordpro_source_filter_localtime.cxx,v 1.1 2018/04/19 18:07:03 mrg Exp $

add missing ICU namespace needed for icu 61.

--- lotuswordpro/source/filter/localtime.cxx.orig	2018-03-29 15:04:09.000000000 +0000
+++ lotuswordpro/source/filter/localtime.cxx	2018-04-19 09:34:48.018480883 +0000
@@ -57,6 +57,8 @@
 #include <limits.h>
 #include <unicode/timezone.h>
 
+using namespace U_ICU_NAMESPACE;
+
 const long DAY_SEC =24 * 60 * 60;
 const long YEAR_SEC = 365 * DAY_SEC;
 const long FOURYEAR_SEC = 4 * YEAR_SEC + DAY_SEC;
