$NetBSD: patch-pdns_tcpreceiver.cc,v 1.4 2015/06/10 16:24:44 fhajny Exp $

Resolve boost symbol ambiguity.
--- pdns/tcpreceiver.cc.orig	2015-04-23 08:10:09.000000000 +0000
+++ pdns/tcpreceiver.cc
@@ -173,7 +173,7 @@ void connectWithTimeout(int fd, struct s
   ;
 }
 
-void TCPNameserver::sendPacket(shared_ptr<DNSPacket> p, int outsock)
+void TCPNameserver::sendPacket(boost::shared_ptr<DNSPacket> p, int outsock)
 {
 
   /* Query statistics */
@@ -203,7 +203,7 @@ catch(NetworkError& ae) {
   throw NetworkError("Error reading DNS data from TCP client "+remote.toString()+": "+ae.what());
 }
 
-static void proxyQuestion(shared_ptr<DNSPacket> packet)
+static void proxyQuestion(boost::shared_ptr<DNSPacket> packet)
 {
   int sock=socket(AF_INET, SOCK_STREAM, 0);
   
@@ -247,7 +247,7 @@ static void proxyQuestion(shared_ptr<DNS
 
 void *TCPNameserver::doConnection(void *data)
 {
-  shared_ptr<DNSPacket> packet;
+  boost::shared_ptr<DNSPacket> packet;
   // Fix gcc-4.0 error (on AMD64)
   int fd=(int)(long)data; // gotta love C (generates a harmless warning on opteron)
   pthread_detach(pthread_self());
@@ -287,7 +287,7 @@ void *TCPNameserver::doConnection(void *
       getQuestion(fd, mesg.get(), pktlen, remote);
       S.inc("tcp-queries");      
 
-      packet=shared_ptr<DNSPacket>(new DNSPacket);
+      packet=boost::shared_ptr<DNSPacket>(new DNSPacket);
       packet->setRemote(&remote);
       packet->d_tcp=true;
       packet->setSocket(fd);
@@ -306,8 +306,8 @@ void *TCPNameserver::doConnection(void *
         continue;
       }
 
-      shared_ptr<DNSPacket> reply; 
-      shared_ptr<DNSPacket> cached= shared_ptr<DNSPacket>(new DNSPacket);
+      boost::shared_ptr<DNSPacket> reply; 
+      boost::shared_ptr<DNSPacket> cached= boost::shared_ptr<DNSPacket>(new DNSPacket);
       if(logDNSQueries)  {
         string remote;
         if(packet->hasEDNSSubnet()) 
@@ -341,7 +341,7 @@ void *TCPNameserver::doConnection(void *
         }
         bool shouldRecurse;
 
-        reply=shared_ptr<DNSPacket>(s_P->questionOrRecurse(packet.get(), &shouldRecurse)); // we really need to ask the backend :-)
+        reply=boost::shared_ptr<DNSPacket>(s_P->questionOrRecurse(packet.get(), &shouldRecurse)); // we really need to ask the backend :-)
 
         if(shouldRecurse) {
           proxyQuestion(packet);
@@ -388,7 +388,7 @@ void *TCPNameserver::doConnection(void *
 
 
 // call this method with s_plock held!
-bool TCPNameserver::canDoAXFR(shared_ptr<DNSPacket> q)
+bool TCPNameserver::canDoAXFR(boost::shared_ptr<DNSPacket> q)
 {
   if(::arg().mustDo("disable-axfr"))
     return false;
@@ -499,9 +499,9 @@ namespace {
     return soa;
   }
 
-  shared_ptr<DNSPacket> getFreshAXFRPacket(shared_ptr<DNSPacket> q)
+  boost::shared_ptr<DNSPacket> getFreshAXFRPacket(boost::shared_ptr<DNSPacket> q)
   {
-    shared_ptr<DNSPacket> ret = shared_ptr<DNSPacket>(q->replyPacket());
+    boost::shared_ptr<DNSPacket> ret = boost::shared_ptr<DNSPacket>(q->replyPacket());
     ret->setCompress(false);
     ret->d_dnssecOk=false; // RFC 5936, 2.2.5
     ret->d_tcp = true;
@@ -511,9 +511,9 @@ namespace {
 
 
 /** do the actual zone transfer. Return 0 in case of error, 1 in case of success */
-int TCPNameserver::doAXFR(const string &target, shared_ptr<DNSPacket> q, int outsock)
+int TCPNameserver::doAXFR(const string &target, boost::shared_ptr<DNSPacket> q, int outsock)
 {
-  shared_ptr<DNSPacket> outpacket= getFreshAXFRPacket(q);
+  boost::shared_ptr<DNSPacket> outpacket= getFreshAXFRPacket(q);
   if(q->d_dnssecOk)
     outpacket->d_dnssecOk=true; // RFC 5936, 2.2.5 'SHOULD'
 
@@ -935,9 +935,9 @@ int TCPNameserver::doAXFR(const string &
   return 1;
 }
 
-int TCPNameserver::doIXFR(shared_ptr<DNSPacket> q, int outsock)
+int TCPNameserver::doIXFR(boost::shared_ptr<DNSPacket> q, int outsock)
 {
-  shared_ptr<DNSPacket> outpacket=getFreshAXFRPacket(q);
+  boost::shared_ptr<DNSPacket> outpacket=getFreshAXFRPacket(q);
   if(q->d_dnssecOk)
     outpacket->d_dnssecOk=true; // RFC 5936, 2.2.5 'SHOULD'
 
