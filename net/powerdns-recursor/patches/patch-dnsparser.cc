$NetBSD: patch-dnsparser.cc,v 1.2 2015/06/10 14:22:29 fhajny Exp $

Straighten Boost namespace.

--- dnsparser.cc.orig	2015-04-21 13:02:57.000000000 +0000
+++ dnsparser.cc
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
