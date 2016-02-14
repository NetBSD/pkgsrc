$NetBSD: patch-js_src_jsapi.cpp,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- js/src/jsapi.cpp.orig	2015-04-29 21:11:46.000000000 +0000
+++ js/src/jsapi.cpp
@@ -115,7 +115,7 @@ using js::frontend::Parser;
 #define JS_ADDRESSOF_VA_LIST(ap) (&(ap))
 #endif
 
-bool
+JS_PUBLIC_API(bool)
 JS::CallArgs::requireAtLeast(JSContext* cx, const char* fnname, unsigned required) {
     if (length() < required) {
         char numArgsStr[40];
