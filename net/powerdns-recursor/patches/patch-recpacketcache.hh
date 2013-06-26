$NetBSD: patch-recpacketcache.hh,v 1.1 2013/06/26 15:52:22 joerg Exp $

--- recpacketcache.hh.orig	2010-09-21 16:22:09.000000000 +0000
+++ recpacketcache.hh
@@ -60,8 +60,8 @@ inline bool RecursorPacketCache::Entry::
   const struct dnsheader* 
     dh=(const struct dnsheader*) d_packet.c_str(), 
     *rhsdh=(const struct dnsheader*)rhs.d_packet.c_str();
-  if(make_tuple(dh->opcode, dh->rd, dh->qdcount) < 
-     make_tuple(rhsdh->opcode, rhsdh->rd, rhsdh->qdcount))
+  if(boost::make_tuple(dh->opcode, dh->rd, dh->qdcount) < 
+     boost::make_tuple(rhsdh->opcode, rhsdh->rd, rhsdh->qdcount))
     return true;
 
   return dnspacketLessThan(d_packet, rhs.d_packet);
