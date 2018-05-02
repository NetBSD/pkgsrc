$NetBSD: patch-jsstrinlines.h,v 1.1 2018/05/02 12:42:51 jperkin Exp $

Implement Debian disable-static-strings-on-ia64.patch fix.

--- jsstrinlines.h.orig	2011-03-31 19:08:36.000000000 +0000
+++ jsstrinlines.h
@@ -215,52 +215,75 @@ StringBuffer::checkLength(size_t length)
 inline JSFlatString *
 JSString::unitString(jschar c)
 {
+#ifdef JS_HAS_STATIC_STRINGS
     JS_ASSERT(c < UNIT_STRING_LIMIT);
     return const_cast<JSString *>(&unitStringTable[c])->assertIsFlat();
+#else
+    JS_NOT_REACHED("no static strings");
+	return NULL;
+#endif
 }
 
 inline JSLinearString *
 JSString::getUnitString(JSContext *cx, JSString *str, size_t index)
 {
     JS_ASSERT(index < str->length());
+#ifdef JS_HAS_STATIC_STRINGS
     const jschar *chars = str->getChars(cx);
     if (!chars)
         return NULL;
     jschar c = chars[index];
     if (c < UNIT_STRING_LIMIT)
         return unitString(c);
+#endif
     return js_NewDependentString(cx, str, index, 1);
 }
 
 inline JSFlatString *
 JSString::length2String(jschar c1, jschar c2)
 {
+#ifdef JS_HAS_STATIC_STRINGS
     JS_ASSERT(fitsInSmallChar(c1));
     JS_ASSERT(fitsInSmallChar(c2));
     return const_cast<JSString *> (
              &length2StringTable[(((size_t)toSmallChar[c1]) << 6) + toSmallChar[c2]]
            )->assertIsFlat();
+#else
+    JS_NOT_REACHED("no static strings");
+	return NULL;
+#endif
 }
 
 inline JSFlatString *
 JSString::length2String(uint32 i)
 {
+#ifdef JS_HAS_STATIC_STRINGS
     JS_ASSERT(i < 100);
     return length2String('0' + i / 10, '0' + i % 10);
+#else
+    JS_NOT_REACHED("no static strings");
+	return NULL;
+#endif
 }
 
 inline JSFlatString *
 JSString::intString(jsint i)
 {
+#ifdef JS_HAS_STATIC_STRINGS
     jsuint u = jsuint(i);
     JS_ASSERT(u < INT_STRING_LIMIT);
     return const_cast<JSString *>(JSString::intStringTable[u])->assertIsFlat();
+#else
+    JS_NOT_REACHED("no static strings");
+	return NULL;
+#endif
 }
 
 /* Get a static atomized string for chars if possible. */
 inline JSFlatString *
 JSString::lookupStaticString(const jschar *chars, size_t length)
 {
+#ifdef JS_HAS_STATIC_STRINGS
     if (length == 1) {
         if (chars[0] < UNIT_STRING_LIMIT)
             return unitString(chars[0]);
@@ -290,6 +313,7 @@ JSString::lookupStaticString(const jscha
                 return intString(i);
         }
     }
+#endif
 
     return NULL;
 }
