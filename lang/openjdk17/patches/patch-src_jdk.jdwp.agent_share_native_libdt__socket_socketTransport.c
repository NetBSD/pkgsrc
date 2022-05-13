$NetBSD: patch-src_jdk.jdwp.agent_share_native_libdt__socket_socketTransport.c,v 1.1 2022/05/13 14:24:19 ryoon Exp $

--- src/jdk.jdwp.agent/share/native/libdt_socket/socketTransport.c.orig	2022-02-05 03:44:09.000000000 +0000
+++ src/jdk.jdwp.agent/share/native/libdt_socket/socketTransport.c
@@ -392,7 +392,7 @@ parseAddress(const char *address, struct
          * pass hostname == NULL to getaddrinfo.
          */
         hints.ai_family = allowOnlyIPv4 ? AF_INET : AF_INET6;
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__)
         hints.ai_flags |= AI_PASSIVE;
 #else
         hints.ai_flags |= AI_PASSIVE | (allowOnlyIPv4 ? 0 : AI_V4MAPPED | AI_ALL);
