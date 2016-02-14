$NetBSD: patch-js_xpconnect_src_xpcprivate.h,v 1.1 2016/02/14 07:30:54 ryoon Exp $

From commit log 1.1:
  Instantiate WeakMapPtr explicitly to get the right visibility with
  clang.

--- js/xpconnect/src/xpcprivate.h.orig	2015-01-23 06:00:06.000000000 +0000
+++ js/xpconnect/src/xpcprivate.h
@@ -1016,6 +1016,8 @@ static inline bool IS_PROTO_CLASS(const 
 /***************************************************************************/
 // XPCWrappedNativeScope is one-to-one with a JS global object.
 
+extern template class JS_PUBLIC_API(JS::WeakMapPtr)<JSObject*, JSObject*>;
+
 class nsIAddonInterposition;
 class nsXPCComponentsBase;
 class XPCWrappedNativeScope : public PRCList
