$NetBSD: patch-pdns_dnsparser.hh,v 1.3 2015/03/27 23:37:52 rodent Exp $

Resolve boost symbol ambiguity.
--- pdns/dnsparser.hh.orig	2015-03-02 13:17:09.000000000 +0000
+++ pdns/dnsparser.hh
@@ -183,7 +183,7 @@ public:
     return record;
   }
 
-  static shared_ptr<DNSRecordContent> unserialize(const string& qname, uint16_t qtype, const string& serialized);
+  static boost::shared_ptr<DNSRecordContent> unserialize(const string& qname, uint16_t qtype, const string& serialized);
 
   void doRecordCheck(const struct DNSRecord&){}
 
@@ -327,9 +327,9 @@ public:
   //! All answers contained in this packet
   answers_t d_answers;
 
-  shared_ptr<PacketReader> getPacketReader(uint16_t offset)
+  boost::shared_ptr<PacketReader> getPacketReader(uint16_t offset)
   {
-    shared_ptr<PacketReader> pr(new PacketReader(d_content));
+    boost::shared_ptr<PacketReader> pr(new PacketReader(d_content));
     pr->d_pos=offset;
     return pr;
   }
