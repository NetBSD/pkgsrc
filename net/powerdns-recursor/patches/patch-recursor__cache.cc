$NetBSD: patch-recursor__cache.cc,v 1.2 2015/06/10 14:22:29 fhajny Exp $

Straighten Boost namespace.

--- recursor_cache.cc.orig	2015-04-21 13:02:57.000000000 +0000
+++ recursor_cache.cc
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
