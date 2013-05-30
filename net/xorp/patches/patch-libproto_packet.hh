$NetBSD: patch-libproto_packet.hh,v 1.1 2013/05/30 15:37:24 joerg Exp $

--- libproto/packet.hh.orig	2013-04-29 19:23:03.000000000 +0000
+++ libproto/packet.hh
@@ -414,11 +414,11 @@ public:
 	  _ip_src(_data + _ip_src_offset),
 	  _ip_dst(_data + _ip_dst_offset)
     {
-	static_assert(IpHeader4::SIZE == _ip_vhl_sizeof + _ip_tos_sizeof
+	my_static_assert(IpHeader4::SIZE == _ip_vhl_sizeof + _ip_tos_sizeof
 		      + _ip_len_sizeof + _ip_id_sizeof + _ip_off_sizeof
 		      + _ip_ttl_sizeof + _ip_p_sizeof + _ip_sum_sizeof
 		      + _ip_src_sizeof + _ip_dst_sizeof);
-	static_assert(IpHeader4::SIZE == _ip_dst_offset + _ip_dst_sizeof);
+	my_static_assert(IpHeader4::SIZE == _ip_dst_offset + _ip_dst_sizeof);
     }
 
     static const size_t SIZE = 20;		// The header size
@@ -708,10 +708,10 @@ public:
 	  _ip_src(_data + _ip_src_offset),
 	  _ip_dst(_data + _ip_dst_offset)
     {
-	static_assert(IpHeader6::SIZE == _ip_vtc_flow_sizeof
+	my_static_assert(IpHeader6::SIZE == _ip_vtc_flow_sizeof
 		      + _ip_plen_sizeof + _ip_nxt_sizeof + _ip_hlim_sizeof
 		      + _ip_src_sizeof + _ip_dst_sizeof);
-	static_assert(IpHeader6::SIZE == _ip_dst_offset + _ip_dst_sizeof);
+	my_static_assert(IpHeader6::SIZE == _ip_dst_offset + _ip_dst_sizeof);
     }
 
     static const size_t SIZE = 40;		// The header size
