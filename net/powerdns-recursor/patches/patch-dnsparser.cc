$NetBSD: patch-dnsparser.cc,v 1.1 2013/06/26 15:52:22 joerg Exp $

--- dnsparser.cc.orig	2010-09-21 16:22:09.000000000 +0000
+++ dnsparser.cc
@@ -106,7 +106,7 @@ static const string EncodeDNSLabel(const
 }
 
 
-shared_ptr<DNSRecordContent> DNSRecordContent::unserialize(const string& qname, uint16_t qtype, const string& serialized)
+boost::shared_ptr<DNSRecordContent> DNSRecordContent::unserialize(const string& qname, uint16_t qtype, const string& serialized)
 {
   dnsheader dnsheader;
   memset(&dnsheader, 0, sizeof(dnsheader));
@@ -140,7 +140,7 @@ shared_ptr<DNSRecordContent> DNSRecordCo
   memcpy(&packet[pos], serialized.c_str(), serialized.size()); pos+=(uint16_t)serialized.size();
 
   MOADNSParser mdp((char*)&*packet.begin(), (unsigned int)packet.size());
-  shared_ptr<DNSRecordContent> ret= mdp.d_answers.begin()->first.d_content;
+  boost::shared_ptr<DNSRecordContent> ret= mdp.d_answers.begin()->first.d_content;
   ret->header.d_type=ret->d_qtype;
   ret->label=mdp.d_answers.begin()->first.d_label;
   ret->header.d_ttl=mdp.d_answers.begin()->first.d_ttl;
