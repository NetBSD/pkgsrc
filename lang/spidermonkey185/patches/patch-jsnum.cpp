$NetBSD: patch-jsnum.cpp,v 1.1 2018/05/02 12:42:51 jperkin Exp $

Implement Debian disable-static-strings-on-ia64.patch fix.

--- jsnum.cpp.orig	2011-03-31 19:08:36.000000000 +0000
+++ jsnum.cpp
@@ -605,8 +605,10 @@ js_IntToString(JSContext *cx, int32 si)
 {
     uint32 ui;
     if (si >= 0) {
+#ifdef JS_HAS_STATIC_STRINGS
         if (si < INT_STRING_LIMIT)
             return JSString::intString(si);
+#endif
         ui = si;
     } else {
         ui = uint32(-si);
@@ -1169,6 +1171,7 @@ js_NumberToStringWithBase(JSContext *cx,
 
     int32_t i;
     if (JSDOUBLE_IS_INT32(d, &i)) {
+#ifdef JS_HAS_STATIC_STRINGS
         if (base == 10 && jsuint(i) < INT_STRING_LIMIT)
             return JSString::intString(i);
         if (jsuint(i) < jsuint(base)) {
@@ -1176,6 +1179,7 @@ js_NumberToStringWithBase(JSContext *cx,
                 return JSString::intString(i);
             return JSString::unitString(jschar('a' + i - 10));
         }
+#endif
 
         if (JSString *str = c->dtoaCache.lookup(base, d))
             return str;
