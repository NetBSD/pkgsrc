$NetBSD: patch-rip_packets.hh,v 1.1 2013/05/30 15:37:24 joerg Exp $

--- rip/packets.hh.orig	2013-04-29 19:23:15.000000000 +0000
+++ rip/packets.hh
@@ -51,9 +51,9 @@ public:
 	  _unused0(_data + _unused0_offset),
 	  _unused1(_data + _unused1_offset)
     {
-	static_assert(RipPacketHeader::SIZE == _command_sizeof
+	my_static_assert(RipPacketHeader::SIZE == _command_sizeof
 		      + _version_sizeof + _unused0_sizeof + _unused1_sizeof);
-	static_assert(RipPacketHeader::SIZE == _unused1_offset
+	my_static_assert(RipPacketHeader::SIZE == _unused1_offset
 		      + _unused1_sizeof);
     }
 
@@ -220,10 +220,10 @@ public:
 	  _nh(_data + _nh_offset),
 	  _metric(_data + _metric_offset)
     {
-	static_assert(PacketRouteEntry<IPv4>::SIZE == _af_sizeof + _tag_sizeof
+	my_static_assert(PacketRouteEntry<IPv4>::SIZE == _af_sizeof + _tag_sizeof
 		      + _addr_sizeof + _mask_sizeof + _nh_sizeof
 		      + _metric_sizeof);
-	static_assert(PacketRouteEntry<IPv4>::SIZE == _metric_offset
+	my_static_assert(PacketRouteEntry<IPv4>::SIZE == _metric_offset
 		      + _metric_sizeof);
     }
 
@@ -406,9 +406,9 @@ public:
 	  _auth(_data + _auth_offset),
 	  _pw(_data + _pw_offset)
     {
-	static_assert(PlaintextPacketRouteEntry4::SIZE == _af_sizeof
+	my_static_assert(PlaintextPacketRouteEntry4::SIZE == _af_sizeof
 		      + _auth_sizeof + _pw_sizeof);
-	static_assert(PlaintextPacketRouteEntry4::SIZE == _pw_offset 
+	my_static_assert(PlaintextPacketRouteEntry4::SIZE == _pw_offset 
 		      + _pw_sizeof);
     }
 
@@ -532,10 +532,10 @@ public:
 	  _seqno(_data + _seqno_offset),
 	  _mbz(_data + _mbz_offset)
     {
-	static_assert(MD5PacketRouteEntry4::SIZE == _af_sizeof + _auth_sizeof
+	my_static_assert(MD5PacketRouteEntry4::SIZE == _af_sizeof + _auth_sizeof
 		      + _auth_off_sizeof + _key_id_sizeof + _auth_bytes_sizeof
 		      + _seqno_sizeof + _mbz_sizeof);
-	static_assert(MD5PacketRouteEntry4::SIZE == _mbz_offset + _mbz_sizeof);
+	my_static_assert(MD5PacketRouteEntry4::SIZE == _mbz_offset + _mbz_sizeof);
     }
 
     static const size_t SIZE = 20;	// The entry size
@@ -665,9 +665,9 @@ public:
 	  _one(_data + _one_offset),
 	  _auth_data(_data + _auth_data_offset)
     {
-	static_assert(MD5PacketTrailer::SIZE == _af_sizeof + _one_sizeof
+	my_static_assert(MD5PacketTrailer::SIZE == _af_sizeof + _one_sizeof
 		      + _auth_data_sizeof);
-	static_assert(MD5PacketTrailer::SIZE == _auth_data_offset
+	my_static_assert(MD5PacketTrailer::SIZE == _auth_data_offset
 		      + _auth_data_sizeof);
     }
 
@@ -774,9 +774,9 @@ public:
 	  _prefix_len(_data + _prefix_len_offset),
 	  _metric(_data + _metric_offset)
     {
-	static_assert(PacketRouteEntry<IPv6>::SIZE == _prefix_sizeof
+	my_static_assert(PacketRouteEntry<IPv6>::SIZE == _prefix_sizeof
 		      + _tag_sizeof + _prefix_len_sizeof + _metric_sizeof);
-	static_assert(PacketRouteEntry<IPv6>::SIZE == _metric_offset
+	my_static_assert(PacketRouteEntry<IPv6>::SIZE == _metric_offset
 		      + _metric_sizeof);
     }
 
