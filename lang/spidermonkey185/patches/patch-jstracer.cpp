$NetBSD: patch-jstracer.cpp,v 1.1 2018/05/02 12:42:51 jperkin Exp $

Implement Debian disable-static-strings-on-ia64.patch fix.

--- jstracer.cpp.orig	2011-03-31 19:08:36.000000000 +0000
+++ jstracer.cpp
@@ -11505,6 +11505,7 @@ TraceRecorder::callNative(uintN argc, JS
             }
             if (vp[1].isString()) {
                 JSString *str = vp[1].toString();
+#ifdef JS_HAS_STATIC_STRINGS
                 if (native == js_str_charAt) {
                     jsdouble i = vp[2].toNumber();
                     if (JSDOUBLE_IS_NaN(i))
@@ -11518,7 +11519,9 @@ TraceRecorder::callNative(uintN argc, JS
                     set(&vp[0], char_ins);
                     pendingSpecializedNative = IGNORE_NATIVE_CALL_COMPLETE_CALLBACK;
                     return RECORD_CONTINUE;
-                } else if (native == js_str_charCodeAt) {
+                } else
+#endif
+				if (native == js_str_charCodeAt) {
                     jsdouble i = vp[2].toNumber();
                     if (JSDOUBLE_IS_NaN(i))
                       i = 0;
@@ -12967,6 +12970,7 @@ TraceRecorder::getCharCodeAt(JSString *s
 JS_STATIC_ASSERT(sizeof(JSString) == 16 || sizeof(JSString) == 32);
 
 
+#ifdef JS_HAS_STATIC_STRINGS
 JS_REQUIRES_STACK LIns*
 TraceRecorder::getUnitString(LIns* str_ins, LIns* idx_ins)
 {
@@ -13010,6 +13014,7 @@ TraceRecorder::getCharAt(JSString *str,
     }
     return RECORD_CONTINUE;
 }
+#endif
 
 // Typed array tracing depends on EXPANDED_LOADSTORE and F2I
 #if NJ_EXPANDED_LOADSTORE_SUPPORTED && NJ_F2I_SUPPORTED
@@ -13044,6 +13049,7 @@ TraceRecorder::record_JSOP_GETELEM()
     LIns* obj_ins = get(&lval);
     LIns* idx_ins = get(&idx);
 
+#ifdef JS_HAS_STATIC_STRINGS
     // Special case for array-like access of strings.
     if (lval.isString() && hasInt32Repr(idx)) {
         if (call)
@@ -13056,6 +13062,7 @@ TraceRecorder::record_JSOP_GETELEM()
         set(&lval, char_ins);
         return ARECORD_CONTINUE;
     }
+#endif
 
     if (lval.isPrimitive())
         RETURN_STOP_A("JSOP_GETLEM on a primitive");
