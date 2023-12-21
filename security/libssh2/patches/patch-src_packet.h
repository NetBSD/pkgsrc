$NetBSD: patch-src_packet.h,v 1.1 2023/12/21 07:04:19 wiz Exp $

Terrapin fix
https://github.com/libssh2/libssh2/commit/d34d9258b8420b19ec3f97b4cc5bf7aa7d98e35a

--- src/packet.h.orig	2020-06-02 14:08:06.000000000 +0000
+++ src/packet.h
@@ -71,6 +71,6 @@ int _libssh2_packet_burn(LIBSSH2_SESSION
 int _libssh2_packet_write(LIBSSH2_SESSION * session, unsigned char *data,
                           unsigned long data_len);
 int _libssh2_packet_add(LIBSSH2_SESSION * session, unsigned char *data,
-                        size_t datalen, int macstate);
+                        size_t datalen, int macstate, uint32_t seq);
 
 #endif /* __LIBSSH2_PACKET_H */
