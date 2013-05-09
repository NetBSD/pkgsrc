$NetBSD: patch-pdns_nameserver.cc,v 1.1 2013/05/09 20:06:53 joerg Exp $

--- pdns/nameserver.cc.orig	2013-05-09 15:25:50.000000000 +0000
+++ pdns/nameserver.cc
@@ -181,7 +181,7 @@ void UDPNameserver::send(DNSPacket *p)
   const char *buffer=p->getData();
   DLOG(L<<Logger::Notice<<"Sending a packet to "<< p->remote.toString() <<" ("<<p->len<<" octets)"<<endl);
   if(p->len > p->getMaxReplyLen()) {
-    shared_ptr<DNSPacket> sharedp(new DNSPacket(*p));
+    boost::shared_ptr<DNSPacket> sharedp(new DNSPacket(*p));
     sharedp->truncate(p->getMaxReplyLen());
     buffer=sharedp->getData();
     if(sendto(sharedp->getSocket(),buffer,sharedp->len,0,(struct sockaddr *)(&sharedp->remote), sharedp->remote.getSocklen())<0) 
