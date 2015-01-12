$NetBSD: patch-pdns_dnspacket.cc,v 1.3 2015/01/12 11:40:43 jperkin Exp $

Resolve boost symbol ambiguity.
Avoid ambiguous abs() call.

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
@@ -601,7 +601,7 @@ bool checkForCorrectTSIG(const DNSPacket
   string message;
 
   q->getTSIGDetails(trc, keyname, &message);
-  uint64_t now = time(0);
+  float now = time(0);
   if(abs(trc->d_time - now) > trc->d_fudge) {
     L<<Logger::Error<<"Packet for '"<<q->qdomain<<"' denied: TSIG (key '"<<*keyname<<"') time delta "<< abs(trc->d_time - now)<<" > 'fudge' "<<trc->d_fudge<<endl;
     return false;
