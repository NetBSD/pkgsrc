$NetBSD: patch-pdns_tcpreceiver.cc,v 1.1 2013/05/09 20:06:53 joerg Exp $

--- pdns/tcpreceiver.cc.orig	2013-05-09 15:25:58.000000000 +0000
+++ pdns/tcpreceiver.cc
@@ -170,7 +170,7 @@ void connectWithTimeout(int fd, struct s
   ;
 }
 
-void TCPNameserver::sendPacket(shared_ptr<DNSPacket> p, int outsock)
+void TCPNameserver::sendPacket(boost::shared_ptr<DNSPacket> p, int outsock)
 {
   const char *buf=p->getData();
   uint16_t len=htons(p->len);
@@ -188,7 +188,7 @@ catch(NetworkError& ae) {
   throw NetworkError("Error reading DNS data from TCP client "+remote.toString()+": "+ae.what());
 }
 
-static void proxyQuestion(shared_ptr<DNSPacket> packet)
+static void proxyQuestion(boost::shared_ptr<DNSPacket> packet)
 {
   int sock=socket(AF_INET, SOCK_STREAM, 0);
   if(sock < 0)
@@ -232,7 +232,7 @@ static void proxyQuestion(shared_ptr<DNS
 
 void *TCPNameserver::doConnection(void *data)
 {
-  shared_ptr<DNSPacket> packet;
+  boost::shared_ptr<DNSPacket> packet;
   // Fix gcc-4.0 error (on AMD64)
   int fd=(int)(long)data; // gotta love C (generates a harmless warning on opteron)
   pthread_detach(pthread_self());
@@ -264,7 +264,7 @@ void *TCPNameserver::doConnection(void *
       getQuestion(fd,mesg,pktlen,remote);
       S.inc("tcp-queries");      
 
-      packet=shared_ptr<DNSPacket>(new DNSPacket);
+      packet=boost::shared_ptr<DNSPacket>(new DNSPacket);
       packet->setRemote(&remote);
       packet->d_tcp=true;
       packet->setSocket(fd);
@@ -277,8 +277,8 @@ void *TCPNameserver::doConnection(void *
 	continue;
       }
 
-      shared_ptr<DNSPacket> reply; 
-      shared_ptr<DNSPacket> cached= shared_ptr<DNSPacket>(new DNSPacket);
+      boost::shared_ptr<DNSPacket> reply; 
+      boost::shared_ptr<DNSPacket> cached= boost::shared_ptr<DNSPacket>(new DNSPacket);
 
       if(!packet->d.rd && (PC.get(packet.get(), cached.get()))) { // short circuit - does the PacketCache recognize this question?
 	cached->setRemote(&packet->remote);
@@ -299,7 +299,7 @@ void *TCPNameserver::doConnection(void *
 	}
 	bool shouldRecurse;
 
-	reply=shared_ptr<DNSPacket>(s_P->questionOrRecurse(packet.get(), &shouldRecurse)); // we really need to ask the backend :-)
+	reply=boost::shared_ptr<DNSPacket>(s_P->questionOrRecurse(packet.get(), &shouldRecurse)); // we really need to ask the backend :-)
 
 	if(shouldRecurse) {
 	  proxyQuestion(packet);
@@ -344,7 +344,7 @@ void *TCPNameserver::doConnection(void *
   return 0;
 }
 
-bool TCPNameserver::canDoAXFR(shared_ptr<DNSPacket> q)
+bool TCPNameserver::canDoAXFR(boost::shared_ptr<DNSPacket> q)
 {
   if(::arg().mustDo("disable-axfr"))
     return false;
@@ -363,20 +363,20 @@ bool TCPNameserver::canDoAXFR(shared_ptr
 }
 
 /** do the actual zone transfer. Return 0 in case of error, 1 in case of success */
-int TCPNameserver::doAXFR(const string &target, shared_ptr<DNSPacket> q, int outsock)
+int TCPNameserver::doAXFR(const string &target, boost::shared_ptr<DNSPacket> q, int outsock)
 {
-  shared_ptr<DNSPacket> outpacket;
+  boost::shared_ptr<DNSPacket> outpacket;
   if(!canDoAXFR(q)) {
     L<<Logger::Error<<"AXFR of domain '"<<target<<"' denied to "<<q->getRemote()<<endl;
 
-    outpacket=shared_ptr<DNSPacket>(q->replyPacket());
+    outpacket=boost::shared_ptr<DNSPacket>(q->replyPacket());
     outpacket->setRcode(RCode::Refused); 
     // FIXME: should actually figure out if we are auth over a zone, and send out 9 if we aren't
     sendPacket(outpacket,outsock);
     return 0;
   }
   L<<Logger::Error<<"AXFR of domain '"<<target<<"' initiated by "<<q->getRemote()<<endl;
-  outpacket=shared_ptr<DNSPacket>(q->replyPacket());
+  outpacket=boost::shared_ptr<DNSPacket>(q->replyPacket());
 
   DNSResourceRecord soa;  
   DNSResourceRecord rr;
@@ -450,7 +450,7 @@ int TCPNameserver::doAXFR(const string &
   if(::arg().mustDo("strict-rfc-axfrs"))
     chunk=1;
 
-  outpacket=shared_ptr<DNSPacket>(q->replyPacket());
+  outpacket=boost::shared_ptr<DNSPacket>(q->replyPacket());
   outpacket->setCompress(false);
 
   while(B->get(rr)) {
@@ -464,7 +464,7 @@ int TCPNameserver::doAXFR(const string &
     
       sendPacket(outpacket, outsock);
 
-      outpacket=shared_ptr<DNSPacket>(q->replyPacket());
+      outpacket=boost::shared_ptr<DNSPacket>(q->replyPacket());
       outpacket->setCompress(false);
       // FIXME: Subsequent messages SHOULD NOT have a question section, though the final message MAY.
     }
@@ -475,7 +475,7 @@ int TCPNameserver::doAXFR(const string &
 
   DLOG(L<<"Done writing out records"<<endl);
   /* and terminate with yet again the SOA record */
-  outpacket=shared_ptr<DNSPacket>(q->replyPacket());
+  outpacket=boost::shared_ptr<DNSPacket>(q->replyPacket());
   outpacket->addRecord(soa);
   sendPacket(outpacket, outsock);
   DLOG(L<<"last packet - close"<<endl);
