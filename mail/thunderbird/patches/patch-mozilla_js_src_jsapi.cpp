$NetBSD: patch-mozilla_js_src_jsapi.cpp,v 1.1 2015/07/09 15:17:34 ryoon Exp $

--- mozilla/js/src/jsapi.cpp.orig	2015-06-08 17:49:25.000000000 +0000
+++ mozilla/js/src/jsapi.cpp
@@ -115,7 +115,7 @@ using js::frontend::Parser;
 #define JS_ADDRESSOF_VA_LIST(ap) (&(ap))
 #endif
 
-bool
+JS_PUBLIC_API(bool)
 JS::CallArgs::requireAtLeast(JSContext* cx, const char* fnname, unsigned required) {
     if (length() < required) {
         char numArgsStr[40];
