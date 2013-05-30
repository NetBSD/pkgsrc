$NetBSD: patch-vrrp_vrrp__packet.cc,v 1.1 2013/05/30 15:37:24 joerg Exp $

--- vrrp/vrrp_packet.cc.orig	2013-04-29 19:23:25.000000000 +0000
+++ vrrp/vrrp_packet.cc
@@ -34,8 +34,8 @@ const IPv4 VrrpPacket::mcast_group = IPv
 VrrpHeader&
 VrrpHeader::assign(uint8_t* data)
 {
-    static_assert(sizeof(VrrpHeader) == 8);
-    static_assert(sizeof(VrrpAuth) == 8);
+    my_static_assert(sizeof(VrrpHeader) == 8);
+    my_static_assert(sizeof(VrrpAuth) == 8);
 
     VrrpHeader* vh = reinterpret_cast<VrrpHeader*>(data);
 
