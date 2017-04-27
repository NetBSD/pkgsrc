$NetBSD: patch-mozilla_js_xpconnect_src_xpcprivate.h,v 1.1 2017/04/27 13:38:19 ryoon Exp $

--- mozilla/js/xpconnect/src/xpcprivate.h.orig	2016-04-07 21:33:28.000000000 +0000
+++ mozilla/js/xpconnect/src/xpcprivate.h
@@ -999,6 +999,8 @@ typedef nsTArray<InterpositionWhitelistP
 /***************************************************************************/
 // XPCWrappedNativeScope is one-to-one with a JS global object.
 
+extern template class JS_PUBLIC_API(JS::WeakMapPtr)<JSObject*, JSObject*>;
+
 class nsIAddonInterposition;
 class nsXPCComponentsBase;
 class XPCWrappedNativeScope : public PRCList
