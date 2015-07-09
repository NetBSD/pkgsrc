$NetBSD: patch-mozilla_js_xpconnect_src_xpcprivate.h,v 1.1 2015/07/09 15:17:34 ryoon Exp $

--- mozilla/js/xpconnect/src/xpcprivate.h.orig	2015-06-08 17:49:55.000000000 +0000
+++ mozilla/js/xpconnect/src/xpcprivate.h
@@ -1017,6 +1017,8 @@ static inline bool IS_PROTO_CLASS(const 
 /***************************************************************************/
 // XPCWrappedNativeScope is one-to-one with a JS global object.
 
+extern template class JS_PUBLIC_API(JS::WeakMapPtr)<JSObject*, JSObject*>;
+
 class nsIAddonInterposition;
 class nsXPCComponentsBase;
 class XPCWrappedNativeScope : public PRCList
