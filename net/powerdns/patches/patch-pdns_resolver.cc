$NetBSD: patch-pdns_resolver.cc,v 1.4 2015/03/27 23:37:52 rodent Exp $

Limit inclusion of boost headers to only those necessary to avoid conflicting
types errors on Solaris.
Resolve boost symbol ambiguity.

--- pdns/resolver.cc.orig	2015-03-02 13:17:12.000000000 +0000
+++ pdns/resolver.cc
@@ -33,7 +33,7 @@
 #include <cstring>
 #include <string>
 #include <vector>
-#include <boost/algorithm/string.hpp>
+#include <boost/algorithm/string/erase.hpp>
 #include "dns.hh"
 #include "qtype.hh"
 #include "tcpreceiver.hh"
@@ -286,12 +286,12 @@ bool Resolver::tryGetSOASerial(string* d
   bool gotSOA=false;
   BOOST_FOREACH(const MOADNSParser::answers_t::value_type& drc, mdp.d_answers) {
     if(drc.first.d_type == QType::SOA) {
-      shared_ptr<SOARecordContent> src=boost::dynamic_pointer_cast<SOARecordContent>(drc.first.d_content);
+      boost::shared_ptr<SOARecordContent> src=boost::dynamic_pointer_cast<SOARecordContent>(drc.first.d_content);
       *theirSerial=src->d_st.serial;
       gotSOA = true;
     }
     if(drc.first.d_type == QType::RRSIG) {
-      shared_ptr<RRSIGRecordContent> rrc=boost::dynamic_pointer_cast<RRSIGRecordContent>(drc.first.d_content);
+      boost::shared_ptr<RRSIGRecordContent> rrc=boost::dynamic_pointer_cast<RRSIGRecordContent>(drc.first.d_content);
       if(rrc->d_type == QType::SOA) {
         *theirInception= std::max(*theirInception, rrc->d_siginception);
         *theirExpire = std::max(*theirExpire, rrc->d_sigexpire);
@@ -396,7 +396,7 @@ AXFRRetriever::AXFRRetriever(const Combo
   d_sock = -1;
   try {
     d_sock = makeQuerySocket(local, false); // make a TCP socket
-    d_buf = shared_array<char>(new char[65536]);
+    d_buf = boost::shared_array<char>(new char[65536]);
     d_remote = remote; // mostly for error reporting
     this->connect();
     d_soacount = 0;
@@ -490,7 +490,7 @@ int AXFRRetriever::getChunk(Resolver::re
         checkTSIG = true;
       
       if(answer.first.d_type == QType::TSIG) {
-        shared_ptr<TSIGRecordContent> trc = boost::dynamic_pointer_cast<TSIGRecordContent>(answer.first.d_content);
+        boost::shared_ptr<TSIGRecordContent> trc = boost::dynamic_pointer_cast<TSIGRecordContent>(answer.first.d_content);
         theirMac = trc->d_mac;
         d_trc.d_time = trc->d_time;
         checkTSIG = true;
