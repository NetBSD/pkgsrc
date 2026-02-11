$NetBSD: patch-src_unix_udp.c,v 1.7 2026/02/11 09:05:25 adam Exp $

Apply MacPorts patch-libuv-legacy.diff for pre-10.7 platforms.

--- src/unix/udp.c.orig	2026-02-11 01:57:16.000000000 +0000
+++ src/unix/udp.c
@@ -839,7 +839,8 @@ static int uv__udp_set_membership6(uv_ud
     !defined(__ANDROID__) &&                                        \
     !defined(__DragonFly__) &&                                      \
     !defined(__GNU__) &&                                            \
-    !defined(QNX_IOPKT)
+    !defined(QNX_IOPKT) && \
+    (!defined(__APPLE__) || MAC_OS_X_VERSION_MAX_ALLOWED >= 1070)
 static int uv__udp_set_source_membership4(uv_udp_t* handle,
                                           const struct sockaddr_in* multicast_addr,
                                           const char* interface_addr,
@@ -1051,7 +1052,8 @@ int uv_udp_set_source_membership(uv_udp_
     !defined(__ANDROID__) &&                                        \
     !defined(__DragonFly__) &&                                      \
     !defined(__GNU__) &&                                          \
-    !defined(QNX_IOPKT)
+    !defined(QNX_IOPKT) && \
+    (!defined(__APPLE__) || MAC_OS_X_VERSION_MAX_ALLOWED >= 1070)
   int err;
   union uv__sockaddr mcast_addr;
   union uv__sockaddr src_addr;
