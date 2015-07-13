$NetBSD: patch-mozilla_js_xpconnect_wrapper_XrayWrapper.cpp,v 1.1 2015/07/13 17:49:26 ryoon Exp $

--- mozilla/js/xpconnect/wrappers/XrayWrapper.cpp.orig	2015-05-07 18:53:42.000000000 +0000
+++ mozilla/js/xpconnect/wrappers/XrayWrapper.cpp
@@ -351,7 +351,7 @@ public:
         {
             JSAutoCompartment ac(cx, target);
             if (!JS_GetClassPrototype(cx, key, protop))
-                return nullptr;
+                return false;
         }
         return JS_WrapObject(cx, protop);
     }
