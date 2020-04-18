$NetBSD: patch-.._public_TypeDecls.h,v 1.1 2020/04/18 21:59:15 joerg Exp $

--- ../public/TypeDecls.h.orig	2020-04-18 19:25:46.593269032 +0000
+++ ../public/TypeDecls.h
@@ -22,6 +22,7 @@
 
 #include "js-config.h"
 
+#pragma GCC visibility push(default)
 typedef uint8_t jsbytecode;
 
 class JSAtom;
@@ -89,5 +90,6 @@ typedef PersistentRooted<JS::Symbol*> Pe
 typedef PersistentRooted<Value> PersistentRootedValue;
 
 }  // namespace JS
+#pragma GCC visibility pop(default)
 
 #endif /* js_TypeDecls_h */
