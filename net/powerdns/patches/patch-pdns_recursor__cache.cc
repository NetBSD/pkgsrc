$NetBSD: patch-pdns_recursor__cache.cc,v 1.2 2014/12/10 14:50:09 fhajny Exp $

Resolve boost symbol ambiguity.
--- pdns/recursor_cache.cc.orig	2014-10-30 10:18:22.000000000 +0000
+++ pdns/recursor_cache.cc
@@ -53,7 +53,7 @@ DNSResourceRecord String2DNSRR(const str
       rr.content=".";
   }
   else {
-    shared_ptr<DNSRecordContent> regen=DNSRecordContent::unserialize(qname, qt.getCode(), serial);
+    boost::shared_ptr<DNSRecordContent> regen=DNSRecordContent::unserialize(qname, qt.getCode(), serial);
     rr.content=regen->getZoneRepresentation();
   }
   rr.content.reserve(0);
@@ -79,7 +79,7 @@ string DNSRR2String(const DNSResourceRec
       return simpleCompress(rr.content, rr.qname);
   else {
     string ret;
-    shared_ptr<DNSRecordContent> drc(DNSRecordContent::mastermake(type, 1, rr.content));
+    boost::shared_ptr<DNSRecordContent> drc(DNSRecordContent::mastermake(type, 1, rr.content));
     ret=drc->serialize(rr.qname);
   //  cerr<<"stored '"<<rr.qname<<" '"<<rr.qtype.getName()<<"' '"<<rr.content<<"' as "<<ret.size()<<" bytes"<<endl;
     return ret;
