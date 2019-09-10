$NetBSD: patch-src_unix_udp.c,v 1.1 2019/09/10 11:21:08 adam Exp $

Fix building on NetBSD and OpenBSD.
https://github.com/libuv/libuv/pull/2458

--- src/unix/udp.c.orig	2019-09-10 09:09:18.000000000 +0000
+++ src/unix/udp.c
@@ -659,6 +659,7 @@ static int uv__udp_set_membership6(uv_ud
 }
 
 
+#if !defined(__NetBSD__) && !defined(__OpenBSD__)
 static int uv__udp_set_source_membership4(uv_udp_t* handle,
                                           const struct sockaddr_in* multicast_addr,
                                           const char* interface_addr,
@@ -749,6 +750,7 @@ static int uv__udp_set_source_membership
 
   return 0;
 }
+#endif
 
 
 int uv_udp_init_ex(uv_loop_t* loop, uv_udp_t* handle, unsigned int flags) {
@@ -846,6 +848,7 @@ int uv_udp_set_source_membership(uv_udp_
                                  const char* interface_addr,
                                  const char* source_addr,
                                  uv_membership membership) {
+#if !defined(__NetBSD__) && !defined(__OpenBSD__)
   int err;
   struct sockaddr_storage mcast_addr;
   struct sockaddr_in* mcast_addr4;
@@ -882,6 +885,9 @@ int uv_udp_set_source_membership(uv_udp_
                                         interface_addr,
                                         src_addr4,
                                         membership);
+#else
+  return UV_ENOSYS;
+#endif
 }
 
 
