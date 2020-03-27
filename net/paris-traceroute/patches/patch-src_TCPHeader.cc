$NetBSD: patch-src_TCPHeader.cc,v 1.1 2020/03/27 20:52:19 joerg Exp $

--- src/TCPHeader.cc.orig	2020-03-27 18:20:13.353228023 +0000
+++ src/TCPHeader.cc
@@ -287,21 +287,21 @@ TCPHeader::pack (uint8* data, int length
  */
 void
 TCPHeader::dump () {
-  log(DUMP, "TCP header :");
-  log(DUMP, "source_port        = %d", getSourcePort());
-  log(DUMP, "dest_port          = %d", getDestPort());
-  log(DUMP, "sequence_number    = %d", getSeqNumber());
-  log(DUMP, "ack_number         = %d", getAckNumber());
-  log(DUMP, "flags              = 0x%x", header[13]);
-  log(DUMP, "fin_flag(1)        = %s", getFINFlag() ? "true" : "false");
-  log(DUMP, "syn_flag(2)        = %s", getSYNFlag() ? "true" : "false");
-  log(DUMP, "rst_flag(4)        = %s", getRSTFlag() ? "true" : "false");
-  log(DUMP, "psh_flag(8)        = %s", getPSHFlag() ? "true" : "false");
-  log(DUMP, "ack_flag(16)       = %s", getACKFlag() ? "true" : "false");
-  log(DUMP, "urg_flag(32)       = %s", getURGFlag() ? "true" : "false");
-  log(DUMP, "windown            = %d", getWindow());
-  log(DUMP, "checksum           = %d", getChecksum());
-  log(DUMP, "urgent_pointer     = %d", getUrgentPointer());
+  mylog(DUMP, "TCP header :");
+  mylog(DUMP, "source_port        = %d", getSourcePort());
+  mylog(DUMP, "dest_port          = %d", getDestPort());
+  mylog(DUMP, "sequence_number    = %d", getSeqNumber());
+  mylog(DUMP, "ack_number         = %d", getAckNumber());
+  mylog(DUMP, "flags              = 0x%x", header[13]);
+  mylog(DUMP, "fin_flag(1)        = %s", getFINFlag() ? "true" : "false");
+  mylog(DUMP, "syn_flag(2)        = %s", getSYNFlag() ? "true" : "false");
+  mylog(DUMP, "rst_flag(4)        = %s", getRSTFlag() ? "true" : "false");
+  mylog(DUMP, "psh_flag(8)        = %s", getPSHFlag() ? "true" : "false");
+  mylog(DUMP, "ack_flag(16)       = %s", getACKFlag() ? "true" : "false");
+  mylog(DUMP, "urg_flag(32)       = %s", getURGFlag() ? "true" : "false");
+  mylog(DUMP, "windown            = %d", getWindow());
+  mylog(DUMP, "checksum           = %d", getChecksum());
+  mylog(DUMP, "urgent_pointer     = %d", getUrgentPointer());
 }
 
 /**
@@ -309,7 +309,7 @@ TCPHeader::dump () {
  */
 void
 TCPHeader::dumpRaw () {
-  log(DUMP, "TCP header :");
+  mylog(DUMP, "TCP header :");
   dumpRawData(DUMP, header, header_len);
 }
 
