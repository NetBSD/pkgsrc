$NetBSD: patch-src_UDPHeader.cc,v 1.1 2020/03/27 20:52:19 joerg Exp $

--- src/UDPHeader.cc.orig	2020-03-27 18:20:25.642276689 +0000
+++ src/UDPHeader.cc
@@ -140,11 +140,11 @@ UDPHeader::pack (uint8* data, int length
  */
 void
 UDPHeader::dump () {
-  log(DUMP, "UDP header :");
-  log(DUMP, "source_port        = %d", getSourcePort());
-  log(DUMP, "dest_port          = %d", getDestPort());
-  log(DUMP, "datagram_length    = %d", getDatagramLength());
-  log(DUMP, "checksum           = %d", getChecksum());
+  mylog(DUMP, "UDP header :");
+  mylog(DUMP, "source_port        = %d", getSourcePort());
+  mylog(DUMP, "dest_port          = %d", getDestPort());
+  mylog(DUMP, "datagram_length    = %d", getDatagramLength());
+  mylog(DUMP, "checksum           = %d", getChecksum());
 }
 
 /**
