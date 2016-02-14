$NetBSD: patch-js_public_CallArgs.h,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- js/public/CallArgs.h.orig	2015-04-29 21:11:43.000000000 +0000
+++ js/public/CallArgs.h
@@ -344,7 +344,7 @@ class MOZ_STACK_CLASS CallArgs : public 
      * Returns true if there are at least |required| arguments passed in. If
      * false, it reports an error message on the context.
      */
-    bool requireAtLeast(JSContext* cx, const char* fnname, unsigned required);
+    JS_PUBLIC_API(bool) requireAtLeast(JSContext* cx, const char* fnname, unsigned required);
 
 };
 
