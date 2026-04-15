$NetBSD: patch-gio_tests_iptosmessage.c,v 1.1 2026/04/15 08:33:23 adam Exp $

Fix build on NetBSD.

--- gio/tests/iptosmessage.c.orig	2026-04-15 08:21:11.754862208 +0000
+++ gio/tests/iptosmessage.c
@@ -26,7 +26,7 @@
 
 /* See the g_test_skip() calls below for platform-specific reasons why this test
  * code sometimes needs to be skipped. */
-#if ! (defined(G_OS_WIN32) || defined(__APPLE__) || defined(__GNU__))
+#if ! (defined(G_OS_WIN32) || defined(__APPLE__) || defined(__GNU__) || defined(__NetBSD__))
 
 static GSocketControlMessage *
 send_recv_control_message (GSocketFamily family, GSocketControlMessage *msg)
@@ -116,6 +116,8 @@ test_ip_tos (void)
   g_test_skip ("IP_TOS not supported on macOS.");
 #elif defined(__GNU__)
   g_test_skip ("IP_RECVTOS not supported on Hurd");
+#elif defined(__NetBSD__)
+  g_test_skip ("IP_RECVTOS not supported on NetBSD");
 #else
   GIPTosMessage *smsg;
   GIPTosMessage *rmsg;
@@ -140,6 +142,8 @@ test_ipv6_tclass (void)
   g_test_skip ("IPV6_TCLASS not supported on macOS.");
 #elif defined(__GNU__)
   g_test_skip ("IPV6_RECVTCLASS not supported on Hurd");
+#elif defined(__NetBSD__)
+  g_test_skip ("IPV6_RECVTCLASS not supported on NetBSD");
 #else
   GIPv6TclassMessage *smsg;
   GIPv6TclassMessage *rmsg;
