$NetBSD: patch-pdns_resolver.cc,v 1.2 2013/05/09 20:06:53 joerg Exp $

Limit inclusion of boost headers to only those necessary to avoid conflicting
types errors on Solaris.

--- pdns/resolver.cc.orig	2012-01-05 13:54:51.000000000 +0000
+++ pdns/resolver.cc
@@ -29,7 +29,7 @@
 #include <cstring>
 #include <string>
 #include <vector>
-#include <boost/algorithm/string.hpp>
+#include <boost/algorithm/string/erase.hpp>
 #include "dns.hh"
 #include "qtype.hh"
 #include "tcpreceiver.hh"
@@ -183,7 +183,7 @@ bool Resolver::tryGetSOASerial(string* d
   if(mdp.d_qtype != QType::SOA || mdp.d_answers.begin()->first.d_type != QType::SOA) 
     throw ResolverException("Query to '" + fromaddr.toString() + "' for SOA of '" + *domain + "' returned wrong record type");
 
-  shared_ptr<SOARecordContent> rrc=boost::dynamic_pointer_cast<SOARecordContent>(mdp.d_answers.begin()->first.d_content);
+  boost::shared_ptr<SOARecordContent> rrc=boost::dynamic_pointer_cast<SOARecordContent>(mdp.d_answers.begin()->first.d_content);
 
   *theirSerial=rrc->d_st.serial;
   
@@ -383,10 +383,10 @@ int Resolver::axfrChunk(Resolver::res_t 
 
 Resolver::res_t Resolver::result()
 {
-  shared_ptr<MOADNSParser> mdp;
+  boost::shared_ptr<MOADNSParser> mdp;
   
   try {
-    mdp=shared_ptr<MOADNSParser>(new MOADNSParser((char*)d_buf, d_len));
+    mdp=boost::shared_ptr<MOADNSParser>(new MOADNSParser((char*)d_buf, d_len));
   }
   catch(...) {
     throw ResolverException("resolver: unable to parse packet of "+itoa(d_len)+" bytes");
