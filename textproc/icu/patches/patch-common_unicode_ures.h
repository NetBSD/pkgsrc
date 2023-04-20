$NetBSD: patch-common_unicode_ures.h,v 1.1 2023/04/20 14:42:32 wiz Exp $

Commit 2de88f9d9c07f7e693449f94858d96053222acea / issue 21833
changes UChar_t* to char16_t* in ures.h (lines 815, 840, 862, 885
at least, functions ures_getUnicodeString() and friends).

This breaks compilation of code using -DUCHAR_TYPE=uint16_t.
https://unicode-org.atlassian.net/browse/ICU-22356

Workaround: revert to previous version, like Gentoo does
https://gitweb.gentoo.org/repo/gentoo.git/commit/?id=5a5db7fc59b5ff77e2cf44f51784ed4e87aeab5b

--- common/unicode/ures.h.orig	2023-04-13 21:41:15.000000000 +0000
+++ common/unicode/ures.h
@@ -812,7 +812,7 @@ inline UnicodeString
 ures_getUnicodeString(const UResourceBundle *resB, UErrorCode* status) {
     UnicodeString result;
     int32_t len = 0;
-    const char16_t *r = ures_getString(resB, &len, status);
+    const UChar *r = ures_getString(resB, &len, status);
     if(U_SUCCESS(*status)) {
         result.setTo(true, r, len);
     } else {
@@ -837,7 +837,7 @@ inline UnicodeString
 ures_getNextUnicodeString(UResourceBundle *resB, const char ** key, UErrorCode* status) {
     UnicodeString result;
     int32_t len = 0;
-    const char16_t* r = ures_getNextString(resB, &len, key, status);
+    const UChar* r = ures_getNextString(resB, &len, key, status);
     if(U_SUCCESS(*status)) {
         result.setTo(true, r, len);
     } else {
@@ -859,7 +859,7 @@ inline UnicodeString
 ures_getUnicodeStringByIndex(const UResourceBundle *resB, int32_t indexS, UErrorCode* status) {
     UnicodeString result;
     int32_t len = 0;
-    const char16_t* r = ures_getStringByIndex(resB, indexS, &len, status);
+    const UChar* r = ures_getStringByIndex(resB, indexS, &len, status);
     if(U_SUCCESS(*status)) {
         result.setTo(true, r, len);
     } else {
@@ -882,7 +882,7 @@ inline UnicodeString
 ures_getUnicodeStringByKey(const UResourceBundle *resB, const char* key, UErrorCode* status) {
     UnicodeString result;
     int32_t len = 0;
-    const char16_t* r = ures_getStringByKey(resB, key, &len, status);
+    const UChar* r = ures_getStringByKey(resB, key, &len, status);
     if(U_SUCCESS(*status)) {
         result.setTo(true, r, len);
     } else {
