$NetBSD: patch-rip_port.cc,v 1.1 2013/05/30 15:37:24 joerg Exp $

--- rip/port.cc.orig	2013-04-29 19:23:11.000000000 +0000
+++ rip/port.cc
@@ -781,8 +781,8 @@ Port<A>::port_io_receive(const A&	src_ad
 {
     string why;
 
-    static_assert(RipPacketHeader::SIZE == 4);
-    static_assert(PacketRouteEntry<A>::SIZE == 20);
+    my_static_assert(RipPacketHeader::SIZE == 4);
+    my_static_assert(PacketRouteEntry<A>::SIZE == 20);
 
     if (enabled() == false) {
 	debug_msg("Discarding RIP packet: Port not enabled.");
