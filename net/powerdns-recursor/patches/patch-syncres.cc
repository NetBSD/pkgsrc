$NetBSD: patch-syncres.cc,v 1.1 2013/06/26 15:52:22 joerg Exp $

--- syncres.cc.orig	2010-09-21 16:22:09.000000000 +0000
+++ syncres.cc
@@ -162,7 +162,7 @@ bool SyncRes::doOOBResolve(const string 
   }
   if(somedata) {
     LOG<<prefix<<qname<<": found record in '"<<authdomain<<"', but nothing of the right type, sending SOA"<<endl;
-    ziter=iter->second.d_records.find(make_tuple(authdomain, QType(QType::SOA)));
+    ziter=iter->second.d_records.find(boost::make_tuple(authdomain, QType(QType::SOA)));
     if(ziter!=iter->second.d_records.end()) {
       DNSResourceRecord rr=*ziter;
       rr.d_place=DNSResourceRecord::AUTHORITY;
@@ -177,7 +177,7 @@ bool SyncRes::doOOBResolve(const string 
   string nsdomain(qname);
 
   while(chopOffDotted(nsdomain) && !pdns_iequals(nsdomain, iter->first)) {
-    range=iter->second.d_records.equal_range(make_tuple(nsdomain,QType(QType::NS))); 
+    range=iter->second.d_records.equal_range(boost::make_tuple(nsdomain,QType(QType::NS))); 
     if(range.first==range.second)
       continue;
 
@@ -189,7 +189,7 @@ bool SyncRes::doOOBResolve(const string 
   }
   if(ret.empty()) { 
     LOG<<prefix<<qname<<": no NS match in zone '"<<authdomain<<"' either, handing out SOA"<<endl;
-    ziter=iter->second.d_records.find(make_tuple(authdomain, QType(QType::SOA)));
+    ziter=iter->second.d_records.find(boost::make_tuple(authdomain, QType(QType::SOA)));
     if(ziter!=iter->second.d_records.end()) {
       DNSResourceRecord rr=*ziter;
       rr.d_place=DNSResourceRecord::AUTHORITY;
@@ -862,7 +862,7 @@ int SyncRes::doResolveAt(set<string, CIS
           LOG<<prefix<<qname<<": Trying IP "<< remoteIP->toStringWithPort() <<", asking '"<<qname<<"|"<<qtype.getName()<<"'"<<endl;
           extern NetmaskGroup* g_dontQuery;
           
-          if(t_sstorage->throttle.shouldThrottle(d_now.tv_sec, make_tuple(*remoteIP, qname, qtype.getCode()))) {
+          if(t_sstorage->throttle.shouldThrottle(d_now.tv_sec, boost::make_tuple(*remoteIP, qname, qtype.getCode()))) {
             LOG<<prefix<<qname<<": query throttled "<<endl;
             s_throttledqueries++; d_throttledqueries++;
             continue;
@@ -904,9 +904,9 @@ int SyncRes::doResolveAt(set<string, CIS
         	  t_sstorage->nsSpeeds[*tns].submit(*remoteIP, 1000000, &d_now); // 1 sec
         	}
         	if(resolveret==-1)
-        	  t_sstorage->throttle.throttle(d_now.tv_sec, make_tuple(*remoteIP, qname, qtype.getCode()), 60, 100); // unreachable
+        	  t_sstorage->throttle.throttle(d_now.tv_sec, boost::make_tuple(*remoteIP, qname, qtype.getCode()), 60, 100); // unreachable
         	else
-        	  t_sstorage->throttle.throttle(d_now.tv_sec, make_tuple(*remoteIP, qname, qtype.getCode()), 20, 5);  // timeout
+        	  t_sstorage->throttle.throttle(d_now.tv_sec, boost::make_tuple(*remoteIP, qname, qtype.getCode()), 20, 5);  // timeout
               }
               continue;
             }
@@ -914,7 +914,7 @@ int SyncRes::doResolveAt(set<string, CIS
             break;  // this IP address worked!
           wasLame:; // well, it didn't
             LOG<<prefix<<qname<<": status=NS "<<*tns<<" ("<< remoteIP->toString() <<") is lame for '"<<auth<<"', trying sibling IP or NS"<<endl;
-            t_sstorage->throttle.throttle(d_now.tv_sec, make_tuple(*remoteIP, qname, qtype.getCode()), 60, 100);
+            t_sstorage->throttle.throttle(d_now.tv_sec, boost::make_tuple(*remoteIP, qname, qtype.getCode()), 60, 100);
           }
         }
         
@@ -933,7 +933,7 @@ int SyncRes::doResolveAt(set<string, CIS
         
         if(lwr.d_rcode==RCode::ServFail) {
           LOG<<prefix<<qname<<": "<<*tns<<" returned a ServFail, trying sibling IP or NS"<<endl;
-          t_sstorage->throttle.throttle(d_now.tv_sec,make_tuple(*remoteIP, qname, qtype.getCode()),60,3);
+          t_sstorage->throttle.throttle(d_now.tv_sec,boost::make_tuple(*remoteIP, qname, qtype.getCode()),60,3);
           continue;
         }
         LOG<<prefix<<qname<<": Got "<<(unsigned int)lwr.d_result.size()<<" answers from "<<*tns<<" ("<< remoteIP->toString() <<"), rcode="<<lwr.d_rcode<<", in "<<lwr.d_usec/1000<<"ms"<<endl;
