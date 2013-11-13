$NetBSD: patch-mozilla_netwerk_protocol_http_HttpChannelParent.cpp,v 1.1 2013/11/13 13:27:45 ryoon Exp $

--- mozilla/netwerk/protocol/http/HttpChannelParent.cpp.orig	2012-08-25 00:31:26.000000000 +0000
+++ mozilla/netwerk/protocol/http/HttpChannelParent.cpp
@@ -299,6 +299,13 @@ HttpChannelParent::RecvUpdateAssociatedC
   return true;
 }
 
+// Compiling with a version of GCC <= 4.4 fails with an internal compiler
+// error.
+#if !defined(__GNUC__) || \
+  (__GNUC__ >= 5) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 5)
+#pragma GCC optimize ("O0")
+#endif
+
 bool
 HttpChannelParent::RecvRedirect2Verify(const nsresult& result, 
                                        const RequestHeaderTuples& changedHeaders)
