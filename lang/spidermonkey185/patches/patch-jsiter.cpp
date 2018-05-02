$NetBSD: patch-jsiter.cpp,v 1.1 2018/05/02 12:42:51 jperkin Exp $

Implement Debian disable-static-strings-on-ia64.patch fix.

--- jsiter.cpp.orig	2011-03-31 19:08:36.000000000 +0000
+++ jsiter.cpp
@@ -1002,9 +1002,12 @@ js_IteratorNext(JSContext *cx, JSObject
 
             JSString *str;
             jsint i;
+#ifdef JS_HAS_STATIC_STRINGS
             if (rval->isInt32() && (jsuint(i = rval->toInt32()) < INT_STRING_LIMIT)) {
                 str = JSString::intString(i);
-            } else {
+            } else
+#endif
+            {
                 str = js_ValueToString(cx, *rval);
                 if (!str)
                     return false;
