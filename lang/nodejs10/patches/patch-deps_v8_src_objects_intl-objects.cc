$NetBSD: patch-deps_v8_src_objects_intl-objects.cc,v 1.1 2020/11/14 09:54:23 jperkin Exp $

icu 68.1 compat.

--- deps/v8/src/objects/intl-objects.cc.orig	2020-09-15 13:25:38.000000000 +0000
+++ deps/v8/src/objects/intl-objects.cc
@@ -243,7 +243,7 @@ void SetResolvedDateSettings(Isolate* is
   char result[ULOC_FULLNAME_CAPACITY];
   status = U_ZERO_ERROR;
   uloc_toLanguageTag(icu_locale.getName(), result, ULOC_FULLNAME_CAPACITY,
-                     FALSE, &status);
+                     false, &status);
   if (U_SUCCESS(status)) {
     JSObject::SetProperty(resolved, factory->NewStringFromStaticChars("locale"),
                           factory->NewStringFromAsciiChecked(result),
@@ -422,7 +422,7 @@ void SetResolvedNumericSettings(Isolate*
   char result[ULOC_FULLNAME_CAPACITY];
   UErrorCode status = U_ZERO_ERROR;
   uloc_toLanguageTag(icu_locale.getName(), result, ULOC_FULLNAME_CAPACITY,
-                     FALSE, &status);
+                     false, &status);
   if (U_SUCCESS(status)) {
     JSObject::SetProperty(resolved, factory->NewStringFromStaticChars("locale"),
                           factory->NewStringFromAsciiChecked(result),
@@ -657,7 +657,7 @@ void SetResolvedCollatorSettings(Isolate
   char result[ULOC_FULLNAME_CAPACITY];
   status = U_ZERO_ERROR;
   uloc_toLanguageTag(icu_locale.getName(), result, ULOC_FULLNAME_CAPACITY,
-                     FALSE, &status);
+                     false, &status);
   if (U_SUCCESS(status)) {
     JSObject::SetProperty(resolved, factory->NewStringFromStaticChars("locale"),
                           factory->NewStringFromAsciiChecked(result),
@@ -796,7 +796,7 @@ void SetResolvedBreakIteratorSettings(Is
   char result[ULOC_FULLNAME_CAPACITY];
   status = U_ZERO_ERROR;
   uloc_toLanguageTag(icu_locale.getName(), result, ULOC_FULLNAME_CAPACITY,
-                     FALSE, &status);
+                     false, &status);
   if (U_SUCCESS(status)) {
     JSObject::SetProperty(resolved, factory->NewStringFromStaticChars("locale"),
                           factory->NewStringFromAsciiChecked(result),
