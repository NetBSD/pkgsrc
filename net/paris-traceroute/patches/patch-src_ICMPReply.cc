$NetBSD: patch-src_ICMPReply.cc,v 1.1 2020/03/27 20:52:19 joerg Exp $

--- src/ICMPReply.cc.orig	2020-03-27 18:19:41.060175131 +0000
+++ src/ICMPReply.cc
@@ -180,7 +180,7 @@ ICMPReply::getProcId () {
         ICMPHeader* err_icmp = (ICMPHeader*)getHeader(3);
         return err_icmp->getIdentifier();
       } else { // Protocol not supported : return 0
-        log(DUMP, "Protocol not supported");
+        mylog(DUMP, "Protocol not supported");
         return 0;
       }
   }
@@ -219,12 +219,12 @@ ICMPReply::getID () {
         //return err_ip->getIPId();
         return err_icmp->getSequence();
       } else { // Protocol not supported : return 0
-        log(DUMP, "Protocol not supported");
+        mylog(DUMP, "Protocol not supported");
         return 0;
       }
 
   }
-  log(DUMP, "Unsupported ICMP message");
+  mylog(DUMP, "Unsupported ICMP message");
   return 0;
 }
 
@@ -233,29 +233,29 @@ ICMPReply::getID2 () {
 	ICMPHeader* icmp = (ICMPHeader*)getHeader(1);
 	switch (icmp->getType()) {
     case 0x00:	// Echo reply
-    	log(WARN, "getID2 icmp reply TODO\n");
+    	mylog(WARN, "getID2 icmp reply TODO\n");
       return 0;
     case 0x03:	// Port unreachable
     case 0x0b:	// Time Exceeded
       // Get Erroneous IPv4 header
       IP4Header* err_ip = (IP4Header*)getHeader(2);
       if (err_ip->getProtocol() == 6) { 
-      	log(WARN, "getID2 tcp TODO\n");
+      	mylog(WARN, "getID2 tcp TODO\n");
         return 0;
       } else if (err_ip->getProtocol() == 17) {
         UDPHeader* err_udp = (UDPHeader*)getHeader(3);
         return err_udp->getChecksum();
       } else if (err_ip->getProtocol() == 1) {
-      	log(WARN, "getID2, icmp err TODO\n");
+      	mylog(WARN, "getID2, icmp err TODO\n");
         ICMPHeader* err_icmp = (ICMPHeader*)getHeader(3);
         return 0;
       } else { // Protocol not supported : return 0
-        log(DUMP, "Protocol not supported");
+        mylog(DUMP, "Protocol not supported");
         return 0;
       }
 
   }
-  log(DUMP, "Unsupported ICMP message");
+  mylog(DUMP, "Unsupported ICMP message");
   return 0;
 }
 
@@ -264,29 +264,29 @@ ICMPReply::getID3 () {
 	ICMPHeader* icmp = (ICMPHeader*)getHeader(1);
 	switch (icmp->getType()) {
     case 0x00:	// Echo reply
-    	log(WARN, "getID3 icmp reply TODO\n");
+    	mylog(WARN, "getID3 icmp reply TODO\n");
       return 0;
     case 0x03:	// Port unreachable
     case 0x0b:	// Time Exceeded
       // Get Erroneous IPv4 header
       IP4Header* err_ip = (IP4Header*)getHeader(2);
       if (err_ip->getProtocol() == 6) { 
-      	log(WARN, "getID3 tcp TODO\n");
+      	mylog(WARN, "getID3 tcp TODO\n");
         return 0;
       } else if (err_ip->getProtocol() == 17) {
         UDPHeader* err_udp = (UDPHeader*)getHeader(3);
         return err_udp->getDestPort();
       } else if (err_ip->getProtocol() == 1) {
-      	log(WARN, "getID3, icmp err TODO\n");
+      	mylog(WARN, "getID3, icmp err TODO\n");
         ICMPHeader* err_icmp = (ICMPHeader*)getHeader(3);
         return 0;
       } else { // Protocol not supported : return 0
-        log(DUMP, "Protocol not supported");
+        mylog(DUMP, "Protocol not supported");
         return 0;
       }
 
   }
-  log(DUMP, "Unsupported ICMP message");
+  mylog(DUMP, "Unsupported ICMP message");
   return 0;
 }
 
