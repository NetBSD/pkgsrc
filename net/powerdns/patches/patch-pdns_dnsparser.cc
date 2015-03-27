$NetBSD: patch-pdns_dnsparser.cc,v 1.3 2015/03/27 23:37:52 rodent Exp $

Resolve boost symbol ambiguity.
--- pdns/dnsparser.cc.orig	2015-03-02 13:17:09.000000000 +0000
+++ pdns/dnsparser.cc
@@ -109,7 +109,7 @@ static const string EncodeDNSLabel(const
 }
 
 
-shared_ptr<DNSRecordContent> DNSRecordContent::unserialize(const string& qname, uint16_t qtype, const string& serialized)
+boost::shared_ptr<DNSRecordContent> DNSRecordContent::unserialize(const string& qname, uint16_t qtype, const string& serialized)
 {
   dnsheader dnsheader;
   memset(&dnsheader, 0, sizeof(dnsheader));
@@ -143,7 +143,7 @@ shared_ptr<DNSRecordContent> DNSRecordCo
   memcpy(&packet[pos], serialized.c_str(), serialized.size()); pos+=(uint16_t)serialized.size();
 
   MOADNSParser mdp((char*)&*packet.begin(), (unsigned int)packet.size());
-  shared_ptr<DNSRecordContent> ret= mdp.d_answers.begin()->first.d_content;
+  boost::shared_ptr<DNSRecordContent> ret= mdp.d_answers.begin()->first.d_content;
   ret->header.d_type=ret->d_qtype;
   ret->label=mdp.d_answers.begin()->first.d_label;
   ret->header.d_ttl=mdp.d_answers.begin()->first.d_ttl;
