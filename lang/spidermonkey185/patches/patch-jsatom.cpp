$NetBSD: patch-jsatom.cpp,v 1.1 2018/05/02 12:42:51 jperkin Exp $

Implement Debian disable-static-strings-on-ia64.patch fix.

--- jsatom.cpp.orig	2011-03-31 19:08:36.000000000 +0000
+++ jsatom.cpp
@@ -603,11 +603,13 @@ js_GetExistingStringAtom(JSContext *cx,
     JSString str, *str2;
     JSAtomState *state;
 
+#ifdef JS_HAS_STATIC_STRINGS
     if (length == 1) {
         jschar c = *chars;
         if (c < UNIT_STRING_LIMIT)
             return STRING_TO_ATOM(JSString::unitString(c));
     }
+#endif
 
     str.initFlatNotTerminated((jschar *)chars, length);
     state = &cx->runtime->atomState;
