$NetBSD: patch-i18n_uspoof.cpp,v 1.1 2018/12/11 10:15:56 abs Exp $

ICU-20208 uspoof.cpp function checkImpl should be static
https://github.com/unicode-org/icu/commit/8baff8f03e07d8e02304d0c888d0bb21ad2eeb01

--- i18n/uspoof.cpp.orig	2018-09-29 00:34:42.000000000 +0000
+++ i18n/uspoof.cpp
@@ -547,7 +547,7 @@ uspoof_checkUnicodeString(const USpoofCh
     return uspoof_check2UnicodeString(sc, id, NULL, status);
 }
 
-int32_t checkImpl(const SpoofImpl* This, const UnicodeString& id, CheckResult* checkResult, UErrorCode* status) {
+static int32_t checkImpl(const SpoofImpl* This, const UnicodeString& id, CheckResult* checkResult, UErrorCode* status) {
     U_ASSERT(This != NULL);
     U_ASSERT(checkResult != NULL);
     checkResult->clear();
