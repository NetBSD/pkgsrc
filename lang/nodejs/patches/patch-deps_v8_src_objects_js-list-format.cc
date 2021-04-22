$NetBSD: patch-deps_v8_src_objects_js-list-format.cc,v 1.1 2021/04/22 17:33:04 ryoon Exp $

* Fix build with ICU 69.1. Backported from 16.0.0.

--- deps/v8/src/objects/js-list-format.cc.orig	2021-04-06 19:42:15.000000000 +0000
+++ deps/v8/src/objects/js-list-format.cc
@@ -73,6 +73,30 @@ const char* GetIcuStyleString(JSListForm
   UNREACHABLE();
 }
 
+UListFormatterWidth GetIcuWidth(JSListFormat::Style style) {
+  switch (style) {
+    case JSListFormat::Style::LONG:
+      return ULISTFMT_WIDTH_WIDE;
+    case JSListFormat::Style::SHORT:
+      return ULISTFMT_WIDTH_SHORT;
+    case JSListFormat::Style::NARROW:
+      return ULISTFMT_WIDTH_NARROW;
+  }
+  UNREACHABLE();
+}
+
+UListFormatterType GetIcuType(JSListFormat::Type type) {
+  switch (type) {
+    case JSListFormat::Type::CONJUNCTION:
+      return ULISTFMT_TYPE_AND;
+    case JSListFormat::Type::DISJUNCTION:
+      return ULISTFMT_TYPE_OR;
+    case JSListFormat::Type::UNIT:
+      return ULISTFMT_TYPE_UNITS;
+  }
+  UNREACHABLE();
+}
+
 }  // namespace
 
 MaybeHandle<JSListFormat> JSListFormat::New(Isolate* isolate, Handle<Map> map,
@@ -143,7 +167,7 @@ MaybeHandle<JSListFormat> JSListFormat::
   icu::Locale icu_locale = r.icu_locale;
   UErrorCode status = U_ZERO_ERROR;
   icu::ListFormatter* formatter = icu::ListFormatter::createInstance(
-      icu_locale, GetIcuStyleString(style_enum, type_enum), status);
+      icu_locale, GetIcuType(type_enum), GetIcuWidth(style_enum), status);
   if (U_FAILURE(status) || formatter == nullptr) {
     delete formatter;
     THROW_NEW_ERROR(isolate, NewRangeError(MessageTemplate::kIcuError),
