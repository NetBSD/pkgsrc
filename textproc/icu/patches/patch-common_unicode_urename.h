$NetBSD: patch-common_unicode_urename.h,v 1.1 2018/12/11 10:15:56 abs Exp $

ICU-20208 uspoof.cpp function checkImpl should be static
https://github.com/unicode-org/icu/commit/8baff8f03e07d8e02304d0c888d0bb21ad2eeb01

--- common/unicode/urename.h.orig	2018-10-15 18:02:37.000000000 +0000
+++ common/unicode/urename.h
@@ -110,7 +110,6 @@
 #define _UTF7Data U_ICU_ENTRY_POINT_RENAME(_UTF7Data)
 #define _UTF8Data U_ICU_ENTRY_POINT_RENAME(_UTF8Data)
 #define allowedHourFormatsCleanup U_ICU_ENTRY_POINT_RENAME(allowedHourFormatsCleanup)
-#define checkImpl U_ICU_ENTRY_POINT_RENAME(checkImpl)
 #define cmemory_cleanup U_ICU_ENTRY_POINT_RENAME(cmemory_cleanup)
 #define dayPeriodRulesCleanup U_ICU_ENTRY_POINT_RENAME(dayPeriodRulesCleanup)
 #define deleteAllowedHourFormats U_ICU_ENTRY_POINT_RENAME(deleteAllowedHourFormats)
