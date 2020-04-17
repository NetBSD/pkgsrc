$NetBSD: patch-libxipc_xrl__pf__factory.cc,v 1.1 2020/04/17 00:20:45 joerg Exp $

--- libxipc/xrl_pf_factory.cc.orig	2020-04-16 14:37:52.151875483 +0000
+++ libxipc/xrl_pf_factory.cc
@@ -69,7 +69,7 @@ XrlPFSender*
 XrlPFSenderFactory::create_sender(EventLoop& eventloop,
 				  const char* protocol_colon_address)
 {
-    char *colon = strstr(protocol_colon_address, ":");
+    const char *colon = strstr(protocol_colon_address, ":");
     if (colon == 0) {
 	debug_msg("No colon in supposedly colon separated <protocol><address>"
 		  "combination\n\t\"%s\".\n", protocol_colon_address);
