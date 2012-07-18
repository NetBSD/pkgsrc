$NetBSD: patch-netwerk_protocol_http_HttpChannelParent.cpp,v 1.2 2012/07/18 16:10:06 ryoon Exp $

* Fix build with gcc<4.5, for example, DragonFly 3.0.1.
  See https://bugzilla.mozilla.org/show_bug.cgi?id=621446

--- netwerk/protocol/http/HttpChannelParent.cpp.orig	2012-07-04 16:04:06.000000000 +0000
+++ netwerk/protocol/http/HttpChannelParent.cpp
@@ -340,6 +340,13 @@ HttpChannelParent::RecvUpdateAssociatedC
 // Compiling this with GCC <= 4.4 fails with an internal compiler error
 #pragma GCC optimize ("O0")
 #endif
+// Compiling with a version of GCC <= 4.4 fails with an internal compiler
+// error.
+#if !defined(__GNUC__) || \
+  (__GNUC__ >= 5) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 5)
+#pragma GCC optimize ("O0")
+#endif
+
 
 bool
 HttpChannelParent::RecvRedirect2Verify(const nsresult& result, 
