$NetBSD: patch-libxipc_xrl__pf__stcp__ph.cc,v 1.1 2013/05/30 15:37:24 joerg Exp $

--- libxipc/xrl_pf_stcp_ph.cc.orig	2013-04-29 19:23:23.000000000 +0000
+++ libxipc/xrl_pf_stcp_ph.cc
@@ -62,11 +62,11 @@ STCPPacketHeader::STCPPacketHeader(uint8
       _error_note_bytes(_data + _error_note_bytes_offset),
       _xrl_data_bytes(_data + _xrl_data_bytes_offset)
 {
-    static_assert(STCPPacketHeader::SIZE == _fourcc_sizeof + _major_sizeof
+    my_static_assert(STCPPacketHeader::SIZE == _fourcc_sizeof + _major_sizeof
 		  + _minor_sizeof + _seqno_sizeof + _flags_sizeof + _type_sizeof
 		  + _error_code_sizeof + _error_note_bytes_sizeof
 		  + _xrl_data_bytes_sizeof);
-    static_assert(STCPPacketHeader::SIZE ==
+    my_static_assert(STCPPacketHeader::SIZE ==
 		  _xrl_data_bytes_offset + _xrl_data_bytes_sizeof);
 }
 
