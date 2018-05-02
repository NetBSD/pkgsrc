$NetBSD: patch-jsstr.h,v 1.1 2018/05/02 12:42:51 jperkin Exp $

Implement Debian disable-static-strings-on-ia64.patch fix.

--- jsstr.h.orig	2011-03-31 19:08:36.000000000 +0000
+++ jsstr.h
@@ -57,6 +57,15 @@
 #include "jsvalue.h"
 #include "jscell.h"
 
+#if !defined(__ia64__) && !(defined(SOLARIS) && defined(__x86_64__))
+/*
+ * Don't use static strings on ia64 since the compiler may put the static
+ * memory out of the acceptable 47-bit jsval pointer range.
+ */
+# define JS_HAS_STATIC_STRINGS
+#endif
+
+#ifdef JS_HAS_STATIC_STRINGS
 enum {
     UNIT_STRING_LIMIT        = 256U,
     SMALL_CHAR_LIMIT         = 128U, /* Bigger chars cannot be in a length-2 string. */
@@ -64,6 +73,7 @@ enum {
     INT_STRING_LIMIT         = 256U,
     NUM_HUNDRED_STRINGS      = 156U
 };
+#endif
 
 extern jschar *
 js_GetDependentStringChars(JSString *str);
@@ -380,10 +390,15 @@ struct JSString
     typedef uint8 SmallChar;
 
     static inline bool fitsInSmallChar(jschar c) {
+#ifdef JS_HAS_STATIC_STRINGS
         return c < SMALL_CHAR_LIMIT && toSmallChar[c] != INVALID_SMALL_CHAR;
+#else
+		return false;
+#endif
     }
 
     static inline bool isUnitString(void *ptr) {
+#ifdef JS_HAS_STATIC_STRINGS
         jsuword delta = reinterpret_cast<jsuword>(ptr) -
                         reinterpret_cast<jsuword>(unitStringTable);
         if (delta >= UNIT_STRING_LIMIT * sizeof(JSString))
@@ -392,9 +407,13 @@ struct JSString
         /* If ptr points inside the static array, it must be well-aligned. */
         JS_ASSERT(delta % sizeof(JSString) == 0);
         return true;
+#else
+		return false;
+#endif
     }
 
     static inline bool isLength2String(void *ptr) {
+#ifdef JS_HAS_STATIC_STRINGS
         jsuword delta = reinterpret_cast<jsuword>(ptr) -
                         reinterpret_cast<jsuword>(length2StringTable);
         if (delta >= NUM_SMALL_CHARS * NUM_SMALL_CHARS * sizeof(JSString))
@@ -403,9 +422,13 @@ struct JSString
         /* If ptr points inside the static array, it must be well-aligned. */
         JS_ASSERT(delta % sizeof(JSString) == 0);
         return true;
+#else
+		return false;
+#endif
     }
 
     static inline bool isHundredString(void *ptr) {
+#ifdef JS_HAS_STATIC_STRINGS
         jsuword delta = reinterpret_cast<jsuword>(ptr) -
                         reinterpret_cast<jsuword>(hundredStringTable);
         if (delta >= NUM_HUNDRED_STRINGS * sizeof(JSString))
@@ -414,6 +437,9 @@ struct JSString
         /* If ptr points inside the static array, it must be well-aligned. */
         JS_ASSERT(delta % sizeof(JSString) == 0);
         return true;
+#else
+		return false;
+#endif
     }
 
     static inline bool isStatic(void *ptr) {
@@ -424,6 +450,7 @@ struct JSString
 #pragma align 8 (__1cIJSStringPunitStringTable_, __1cIJSStringSlength2StringTable_, __1cIJSStringShundredStringTable_)
 #endif
 
+#ifdef JS_HAS_STATIC_STRINGS
     static const SmallChar INVALID_SMALL_CHAR = -1;
 
     static const jschar fromSmallChar[];
@@ -436,6 +463,7 @@ struct JSString
      * strings, we keep a table to map from integer to the correct string.
      */
     static const JSString *const intStringTable[];
+#endif
 
     static JSFlatString *unitString(jschar c);
     static JSLinearString *getUnitString(JSContext *cx, JSString *str, size_t index);
