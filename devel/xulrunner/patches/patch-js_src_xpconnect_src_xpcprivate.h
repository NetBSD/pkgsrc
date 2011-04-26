$NetBSD: patch-js_src_xpconnect_src_xpcprivate.h,v 1.1 2011/04/26 14:16:37 tnn Exp $

fix sparc64 strict alignment issue, from martin@

--- js/src/xpconnect/src/xpcprivate.h.orig	2011-02-23 05:53:38.000000000 +0000
+++ js/src/xpconnect/src/xpcprivate.h
@@ -1270,7 +1270,10 @@ private:
     // string class members since we don't want to pay the cost of
     // calling the constructors and destructors when the strings
     // aren't being used.
-    char mStringWrapperData[sizeof(StringWrapperEntry) * XPCCCX_STRING_CACHE_SIZE];
+    union {
+        char store[sizeof(StringWrapperEntry) * XPCCCX_STRING_CACHE_SIZE];
+        void *dummy_to_force_alignement;
+    } mStringWrapperData;
 };
 
 class XPCLazyCallContext
