$NetBSD: patch-src_IP4Header.cc,v 1.1 2020/03/27 20:52:19 joerg Exp $

--- src/IP4Header.cc.orig	2020-03-27 18:19:46.190381099 +0000
+++ src/IP4Header.cc
@@ -343,16 +343,16 @@ IP4Header::packPseudo (uint16 dgram_len,
  */
 void
 IP4Header::dump () {
-  log(DUMP, "IP4 header :");
-  log(DUMP, "tos                = %d", getToS());
-  log(DUMP, "total_length       = %d", getTotalLength());
-  log(DUMP, "ttl                = %d", getTTL());
-  log(DUMP, "protocol           = %d", getProtocol());
+  mylog(DUMP, "IP4 header :");
+  mylog(DUMP, "tos                = %d", getToS());
+  mylog(DUMP, "total_length       = %d", getTotalLength());
+  mylog(DUMP, "ttl                = %d", getTTL());
+  mylog(DUMP, "protocol           = %d", getProtocol());
   struct in_addr addr;
   addr.s_addr = *(uint32*)(header + 12);
-  log(DUMP, "source_address     = %s", inet_ntoa(addr));
+  mylog(DUMP, "source_address     = %s", inet_ntoa(addr));
   addr.s_addr = *(uint32*)(header + 16);
-  log(DUMP, "dest_address       = %s", inet_ntoa(addr));
+  mylog(DUMP, "dest_address       = %s", inet_ntoa(addr));
 }
 
 /**
@@ -360,7 +360,7 @@ IP4Header::dump () {
  */
 void
 IP4Header::dumpRaw () {
-  log(DUMP, "IP4 header :");
+  mylog(DUMP, "IP4 header :");
   dumpRawData(WARN, header, header_len);
 }
 
