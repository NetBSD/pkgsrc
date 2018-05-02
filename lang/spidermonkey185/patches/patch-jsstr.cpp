$NetBSD: patch-jsstr.cpp,v 1.1 2018/05/02 12:42:51 jperkin Exp $

Implement Debian disable-static-strings-on-ia64.patch fix.

--- jsstr.cpp.orig	2011-03-31 19:08:36.000000000 +0000
+++ jsstr.cpp
@@ -3121,6 +3121,8 @@ static JSFunctionSpec string_methods[] =
     JS_FS_END
 };
 
+#ifdef JS_HAS_STATIC_STRINGS
+
 /*
  * Set up some tools to make it easier to generate large tables. After constant
  * folding, for each n, Rn(0) is the comma-separated list R(0), R(1), ..., R(2^n-1).
@@ -3291,6 +3293,8 @@ const JSString *const JSString::intStrin
 #undef R3
 #undef R7
 
+#endif  /* defined(JS_HAS_STATIC_STRINGS) */
+
 JSBool
 js_String(JSContext *cx, uintN argc, Value *vp)
 {
@@ -3331,6 +3335,7 @@ str_fromCharCode(JSContext *cx, uintN ar
         uint16_t code;
         if (!ValueToUint16(cx, argv[0], &code))
             return JS_FALSE;
+#ifdef JS_HAS_STATIC_STRINGS
         if (code < UNIT_STRING_LIMIT) {
             str = JSString::unitString(code);
             if (!str)
@@ -3338,6 +3343,7 @@ str_fromCharCode(JSContext *cx, uintN ar
             vp->setString(str);
             return JS_TRUE;
         }
+#endif
         argv[0].setInt32(code);
     }
     chars = (jschar *) cx->malloc((argc + 1) * sizeof(jschar));
@@ -3367,8 +3373,10 @@ String_fromCharCode(JSContext* cx, int32
 {
     JS_ASSERT(JS_ON_TRACE(cx));
     jschar c = (jschar)i;
+#ifdef JS_HAS_STATIC_STRINGS
     if (c < UNIT_STRING_LIMIT)
         return JSString::unitString(c);
+#endif
     return js_NewStringCopyN(cx, &c, 1);
 }
 #endif
