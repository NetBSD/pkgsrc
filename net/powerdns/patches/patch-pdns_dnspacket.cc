$NetBSD: patch-pdns_dnspacket.cc,v 1.2 2014/12/10 14:50:09 fhajny Exp $

Resolve boost symbol ambiguity.
--- pdns/dnspacket.cc.orig	2014-10-30 10:18:22.000000000 +0000
+++ pdns/dnspacket.cc
@@ -312,7 +312,7 @@ void DNSPacket::wrapup()
           pos->content=".";
         
         pw.startRecord(pos->qname, pos->qtype.getCode(), pos->ttl, pos->qclass, (DNSPacketWriter::Place)pos->d_place); 
-        shared_ptr<DNSRecordContent> drc(DNSRecordContent::mastermake(pos->qtype.getCode(), 1, pos->content)); 
+        boost::shared_ptr<DNSRecordContent> drc(DNSRecordContent::mastermake(pos->qtype.getCode(), 1, pos->content)); 
               drc->toPacket(pw);
         if(pw.size() + 20U > (d_tcp ? 65535 : getMaxReplyLen())) { // 20 = room for EDNS0
           pw.rollback();
