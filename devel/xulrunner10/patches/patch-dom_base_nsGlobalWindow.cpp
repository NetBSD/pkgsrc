$NetBSD: patch-dom_base_nsGlobalWindow.cpp,v 1.1 2013/08/29 12:56:15 joerg Exp $

--- dom/base/nsGlobalWindow.cpp.orig	2013-08-28 16:01:56.000000000 +0000
+++ dom/base/nsGlobalWindow.cpp
@@ -6093,7 +6093,7 @@ PostMessageReadStructuredClone(JSContext
     return runtimeCallbacks->read(cx, reader, tag, data, nsnull);
   }
 
-  return JS_FALSE;
+  return 0;
 }
 
 static JSBool
