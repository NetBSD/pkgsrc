$NetBSD: patch-src_unix_udp.c,v 1.5 2022/01/28 21:13:10 schmonz Exp $

Apply MacPorts patch-libuv-legacy.diff for pre-10.7 platforms.

--- src/unix/udp.c.orig	2022-01-04 14:18:00.000000000 +0000
+++ src/unix/udp.c
@@ -927,7 +927,8 @@ static int uv__udp_set_membership6(uv_ud
     !defined(__NetBSD__) &&                                         \
     !defined(__ANDROID__) &&                                        \
     !defined(__DragonFly__) &&                                      \
-    !defined(__QNX__)
+    !defined(__QNX__) &&                                            \
+    (!defined(__APPLE__) || MAC_OS_X_VERSION_MAX_ALLOWED >= 1070)
 static int uv__udp_set_source_membership4(uv_udp_t* handle,
                                           const struct sockaddr_in* multicast_addr,
                                           const char* interface_addr,
@@ -1119,7 +1120,8 @@ int uv_udp_set_source_membership(uv_udp_
     !defined(__NetBSD__) &&                                         \
     !defined(__ANDROID__) &&                                        \
     !defined(__DragonFly__) &&                                      \
-    !defined(__QNX__)
+    !defined(__QNX__) &&                                            \
+    (!defined(__APPLE__) || MAC_OS_X_VERSION_MAX_ALLOWED >= 1070)
   int err;
   union uv__sockaddr mcast_addr;
   union uv__sockaddr src_addr;
