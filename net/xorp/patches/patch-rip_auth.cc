$NetBSD: patch-rip_auth.cc,v 1.1 2013/05/30 15:37:24 joerg Exp $

--- rip/auth.cc.orig	2013-04-29 19:23:08.000000000 +0000
+++ rip/auth.cc
@@ -255,8 +255,8 @@ PlaintextAuthHandler::authenticate_outbo
     if (head_entries() > 0)
 	first_entry_ptr = packet.route_entry_ptr(0);
 
-    static_assert(PacketRouteEntry<IPv4>::SIZE == 20);
-    static_assert(PlaintextPacketRouteEntry4::SIZE == 20);
+    my_static_assert(PacketRouteEntry<IPv4>::SIZE == 20);
+    my_static_assert(PlaintextPacketRouteEntry4::SIZE == 20);
     XLOG_ASSERT(packet.data_ptr() + RipPacketHeader::size()
 		== first_entry_ptr);
 
@@ -488,7 +488,7 @@ MD5AuthHandler::authenticate_inbound(con
 				     const IPv4&		src_addr,
 				     bool			new_peer)
 {
-    static_assert(MD5PacketTrailer::SIZE == 20);
+    my_static_assert(MD5PacketTrailer::SIZE == 20);
 
     //
     // XXX: if no valid keys, then don't use any authentication
@@ -627,7 +627,7 @@ MD5AuthHandler::authenticate_outbound(Ri
     vector<uint8_t> first_trailer;
     KeyChain::iterator iter;
 
-    static_assert(MD5PacketTrailer::SIZE == 20);
+    my_static_assert(MD5PacketTrailer::SIZE == 20);
 
     //
     // XXX: if no valid keys, then don't use any authentication
