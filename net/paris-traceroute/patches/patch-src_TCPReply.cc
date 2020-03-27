$NetBSD: patch-src_TCPReply.cc,v 1.1 2020/03/27 20:52:19 joerg Exp $

--- src/TCPReply.cc.orig	2020-03-27 18:20:19.472483045 +0000
+++ src/TCPReply.cc
@@ -33,7 +33,7 @@ TCPReply::getType () {
 int TCPReply::getProcId () {
   // Get the TCP header
   TCPHeader* tcp = (TCPHeader*)getHeader(1);
-  //log(WARN, "TCPReply::getProcId TODO %x", tcp->getAckNumber() - 1);
+  //mylog(WARN, "TCPReply::getProcId TODO %x", tcp->getAckNumber() - 1);
   // Return (ack number - 1)
   return (tcp->getAckNumber() - 1) >> 16;
 }
@@ -42,26 +42,26 @@ int
 TCPReply::getID () {
   // Get the TCP header
   TCPHeader* tcp = (TCPHeader*)getHeader(1);
-  //log(WARN, "TCPReply::getId TODO");
+  //mylog(WARN, "TCPReply::getId TODO");
   // Return (ack number - 1)
   return (tcp->getAckNumber() - 1) & 0xffff;
 }
 
 int
 TCPReply::getID2 () {
-	log(WARN, "TCPReply::getID2 TODO");
+	mylog(WARN, "TCPReply::getID2 TODO");
 	return 0;
 }
 
 int
 TCPReply::getID3 () {
-	log(WARN, "TCPReply::getID3 TODO");
+	mylog(WARN, "TCPReply::getID3 TODO");
 	return 0;
 }
 
 int
 TCPReply::getReturnFlowId () {
-	//log(WARN, "getReturnFlowId() TODO\n");
+	//mylog(WARN, "getReturnFlowId() TODO\n");
 	return 0;
 }
 
