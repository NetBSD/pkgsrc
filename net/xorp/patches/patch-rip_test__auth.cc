$NetBSD: patch-rip_test__auth.cc,v 1.1 2013/05/30 15:37:24 joerg Exp $

--- rip/test_auth.cc.orig	2013-04-29 19:23:13.000000000 +0000
+++ rip/test_auth.cc
@@ -260,16 +260,16 @@ test_main()
     string dummy_error_msg;
 
     // Static sizing tests
-    static_assert(RipPacketHeader::SIZE == 4);
-    static_assert(PacketRouteEntry<IPv4>::SIZE == 20);
-    static_assert(RipPacketHeader::SIZE == RIPv2_MIN_PACKET_BYTES);
-    static_assert(RipPacketHeader::SIZE + PacketRouteEntry<IPv4>::SIZE
+    my_static_assert(RipPacketHeader::SIZE == 4);
+    my_static_assert(PacketRouteEntry<IPv4>::SIZE == 20);
+    my_static_assert(RipPacketHeader::SIZE == RIPv2_MIN_PACKET_BYTES);
+    my_static_assert(RipPacketHeader::SIZE + PacketRouteEntry<IPv4>::SIZE
 		  == RIPv2_MIN_AUTH_PACKET_BYTES);
-    static_assert(PacketRouteEntry<IPv4>::SIZE
+    my_static_assert(PacketRouteEntry<IPv4>::SIZE
 		  == PlaintextPacketRouteEntry4::SIZE);
-    static_assert(PacketRouteEntry<IPv4>::SIZE == MD5PacketRouteEntry4::SIZE);
-    static_assert(MD5PacketTrailer::SIZE == 20);
-    static_assert(PacketRouteEntry<IPv4>::SIZE
+    my_static_assert(PacketRouteEntry<IPv4>::SIZE == MD5PacketRouteEntry4::SIZE);
+    my_static_assert(MD5PacketTrailer::SIZE == 20);
+    my_static_assert(PacketRouteEntry<IPv4>::SIZE
 		  == PacketRouteEntry<IPv6>::SIZE);
 
     vector<uint8_t> pkt;
