$NetBSD: patch-deps_v8_src_runtime_runtime-intl.cc,v 1.1 2020/11/14 09:54:23 jperkin Exp $

icu 68.1 compat.

--- deps/v8/src/runtime/runtime-intl.cc.orig	2020-09-15 13:25:38.000000000 +0000
+++ deps/v8/src/runtime/runtime-intl.cc
@@ -85,7 +85,7 @@ RUNTIME_FUNCTION(Runtime_CanonicalizeLan
   char result[ULOC_FULLNAME_CAPACITY];
 
   // Force strict BCP47 rules.
-  uloc_toLanguageTag(icu_result, result, ULOC_FULLNAME_CAPACITY, TRUE, &error);
+  uloc_toLanguageTag(icu_result, result, ULOC_FULLNAME_CAPACITY, true, &error);
 
   if (U_FAILURE(error) || error == U_STRING_NOT_TERMINATED_WARNING) {
     return *factory->NewStringFromAsciiChecked(kInvalidTag);
@@ -132,7 +132,7 @@ RUNTIME_FUNCTION(Runtime_AvailableLocale
 
     error = U_ZERO_ERROR;
     // No need to force strict BCP47 rules.
-    uloc_toLanguageTag(icu_name, result, ULOC_FULLNAME_CAPACITY, FALSE, &error);
+    uloc_toLanguageTag(icu_name, result, ULOC_FULLNAME_CAPACITY, false, &error);
     if (U_FAILURE(error) || error == U_STRING_NOT_TERMINATED_WARNING) {
       // This shouldn't happen, but lets not break the user.
       continue;
@@ -164,7 +164,7 @@ RUNTIME_FUNCTION(Runtime_GetDefaultICULo
   char result[ULOC_FULLNAME_CAPACITY];
   UErrorCode status = U_ZERO_ERROR;
   uloc_toLanguageTag(default_locale.getName(), result, ULOC_FULLNAME_CAPACITY,
-                     FALSE, &status);
+                     false, &status);
   if (U_SUCCESS(status)) {
     return *factory->NewStringFromAsciiChecked(result);
   }
@@ -399,9 +399,9 @@ RUNTIME_FUNCTION(Runtime_InternalCompare
     std::unique_ptr<uc16[]> sap1;
     std::unique_ptr<uc16[]> sap2;
     icu::UnicodeString string_val1(
-        FALSE, GetUCharBufferFromFlat(flat1, &sap1, length1), length1);
+        false, GetUCharBufferFromFlat(flat1, &sap1, length1), length1);
     icu::UnicodeString string_val2(
-        FALSE, GetUCharBufferFromFlat(flat2, &sap2, length2), length2);
+        false, GetUCharBufferFromFlat(flat2, &sap2, length2), length2);
     result = collator->compare(string_val1, string_val2, status);
   }
   if (U_FAILURE(status)) return isolate->ThrowIllegalOperation();
