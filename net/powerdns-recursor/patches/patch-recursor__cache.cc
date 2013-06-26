$NetBSD: patch-recursor__cache.cc,v 1.1 2013/06/26 15:52:22 joerg Exp $

--- recursor_cache.cc.orig	2010-09-21 16:22:09.000000000 +0000
+++ recursor_cache.cc
@@ -52,7 +52,7 @@ DNSResourceRecord String2DNSRR(const str
       rr.content=".";
   }
   else {
-    shared_ptr<DNSRecordContent> regen=DNSRecordContent::unserialize(qname, qt.getCode(), serial);
+    boost::shared_ptr<DNSRecordContent> regen=DNSRecordContent::unserialize(qname, qt.getCode(), serial);
     rr.content=regen->getZoneRepresentation();
   }
   rr.content.reserve(0);
@@ -78,7 +78,7 @@ string DNSRR2String(const DNSResourceRec
       return simpleCompress(rr.content, rr.qname);
   else {
     string ret;
-    shared_ptr<DNSRecordContent> drc(DNSRecordContent::mastermake(type, 1, rr.content));
+    boost::shared_ptr<DNSRecordContent> drc(DNSRecordContent::mastermake(type, 1, rr.content));
     ret=drc->serialize(rr.qname);
   //  cerr<<"stored '"<<rr.qname<<" '"<<rr.qtype.getName()<<"' '"<<rr.content<<"' as "<<ret.size()<<" bytes"<<endl;
     return ret;
@@ -186,7 +186,7 @@ bool MemRecursorCache::attemptToRefreshN
 void MemRecursorCache::replace(time_t now, const string &qname, const QType& qt,  const set<DNSResourceRecord>& content, bool auth)
 {
   d_cachecachevalid=false;
-  tuple<string, uint16_t> key=make_tuple(qname, qt.getCode());
+  boost::tuple<string, uint16_t> key=boost::make_tuple(qname, qt.getCode());
   cache_t::iterator stored=d_cache.find(key);
 
   bool isNew=false;
