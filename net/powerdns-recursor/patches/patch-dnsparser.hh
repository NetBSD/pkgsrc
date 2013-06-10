$NetBSD: patch-dnsparser.hh,v 1.1 2013/06/10 18:59:09 joerg Exp $

--- dnsparser.hh.orig	2013-05-10 14:52:18.000000000 +0000
+++ dnsparser.hh
@@ -167,7 +167,7 @@ public:
     return record;
   }
 
-  static shared_ptr<DNSRecordContent> unserialize(const string& qname, uint16_t qtype, const string& serialized);
+  static boost::shared_ptr<DNSRecordContent> unserialize(const string& qname, uint16_t qtype, const string& serialized);
 
   void doRecordCheck(const struct DNSRecord&){}
 
@@ -305,9 +305,9 @@ public:
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
