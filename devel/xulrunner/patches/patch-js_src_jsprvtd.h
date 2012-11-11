$NetBSD: patch-js_src_jsprvtd.h,v 1.1 2012/11/11 22:26:00 joerg Exp $

--- js/src/jsprvtd.h.orig	2012-10-24 14:32:54.000000000 +0000
+++ js/src/jsprvtd.h
@@ -146,9 +146,9 @@ struct TreeContext;
 class UpvarCookie;
 
 class Proxy;
-class BaseProxyHandler;
-class DirectWrapper;
-class CrossCompartmentWrapper;
+class JS_PUBLIC_API(BaseProxyHandler);
+class JS_PUBLIC_API(DirectWrapper);
+class JS_PUBLIC_API(CrossCompartmentWrapper);
 
 class TempAllocPolicy;
 class RuntimeAllocPolicy;
