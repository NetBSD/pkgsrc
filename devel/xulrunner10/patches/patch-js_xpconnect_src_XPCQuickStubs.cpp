$NetBSD: patch-js_xpconnect_src_XPCQuickStubs.cpp,v 1.1 2013/08/29 12:56:15 joerg Exp $

--- js/xpconnect/src/XPCQuickStubs.cpp.orig	2013-08-28 15:54:22.000000000 +0000
+++ js/xpconnect/src/XPCQuickStubs.cpp
@@ -190,7 +190,7 @@ GeneratePropertyOp(JSContext *cx, JSObje
     JSFunction *fun =
         JS_NewFunctionById(cx, PropertyOpForwarder<Op>, argc, 0, obj, id);
     if (!fun)
-        return JS_FALSE;
+        return 0;
 
     JSObject *funobj = JS_GetFunctionObject(fun);
 
@@ -200,10 +200,10 @@ GeneratePropertyOp(JSContext *cx, JSObje
     // second object to work around this.
     JSObject *ptrobj = JS_NewObject(cx, &PointerHolderClass, nsnull, funobj);
     if (!ptrobj)
-        return JS_FALSE;
+        return 0;
     Op *popp = new Op;
     if (!popp)
-        return JS_FALSE;
+        return 0;
     *popp = pop;
     JS_SetPrivate(cx, ptrobj, popp);
 
