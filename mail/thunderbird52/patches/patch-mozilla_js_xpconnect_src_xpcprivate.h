$NetBSD: patch-mozilla_js_xpconnect_src_xpcprivate.h,v 1.1 2018/12/16 08:29:48 ryoon Exp $

--- mozilla/js/xpconnect/src/xpcprivate.h.orig	2017-04-14 04:53:14.000000000 +0000
+++ mozilla/js/xpconnect/src/xpcprivate.h
@@ -843,6 +843,8 @@ typedef nsTArray<InterpositionWhitelistP
 /***************************************************************************/
 // XPCWrappedNativeScope is one-to-one with a JS global object.
 
+extern template class JS_PUBLIC_API(JS::WeakMapPtr)<JSObject*, JSObject*>;
+
 class nsIAddonInterposition;
 class nsXPCComponentsBase;
 class XPCWrappedNativeScope final : public PRCList
