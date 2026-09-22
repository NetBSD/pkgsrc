$NetBSD: patch-gio_tests_iptosmessage.c,v 1.2 2026/09/22 04:06:12 ryoon Exp $

Fix build on NetBSD.

--- gio/tests/iptosmessage.c.orig	2026-09-09 13:40:59.000000000 +0000
+++ gio/tests/iptosmessage.c
@@ -26,7 +26,7 @@
 
 /* See the g_test_skip() calls below for platform-specific reasons why this test
  * code sometimes needs to be skipped. */
-#if ! (defined(G_OS_WIN32) || defined(__APPLE__) || defined(__GNU__) || defined(_AIX) || defined(__sun__))
+#if ! (defined(G_OS_WIN32) || defined(__APPLE__) || defined(__GNU__) || defined(_AIX) || defined(__sun__) || defined(__NetBSD__))
 
 static GSocketControlMessage *
 send_recv_control_message (GSocketFamily family, GSocketControlMessage *msg)
@@ -120,6 +120,8 @@ test_ip_tos (void)
   g_test_skip ("IP_RECVTOS not supported on AIX");
 #elif defined(__sun__)
   g_test_skip ("IP_RECVTOS not supported on Solaris");
+#elif defined(__NetBSD__)
+  g_test_skip ("IP_RECVTOS not supported on NetBSD");
 #else
   GIPTosMessage *smsg;
   GIPTosMessage *rmsg;
@@ -148,6 +150,8 @@ test_ipv6_tclass (void)
   g_test_skip ("IPV6_RECVTCLASS not supported on AIX");
 #elif defined(__sun__)
   g_test_skip ("IPV6_RECVTCLASS not supported on Solaris");
+#elif defined(__NetBSD__)
+  g_test_skip ("IPV6_RECVTCLASS not supported on NetBSD");
 #else
   GIPv6TclassMessage *smsg;
   GIPv6TclassMessage *rmsg;
