$NetBSD: patch-src_ICMPHeader.cc,v 1.1 2020/03/27 20:52:19 joerg Exp $

--- src/ICMPHeader.cc.orig	2020-03-27 18:19:36.461356104 +0000
+++ src/ICMPHeader.cc
@@ -241,12 +241,12 @@ ICMPHeader::pack (uint8* data, int lengt
  */
 void
 ICMPHeader::dump () {
-  log(DUMP, "ICMP Header :");
-  log(DUMP, "type                = %s", getTypeDesc());
-  log(DUMP, "code                = %s", getCodeDesc());
-  log(DUMP, "checksum            = %d", getChecksum());
-  log(DUMP, "identifier          = %d", getIdentifier());
-  log(DUMP, "sequence            = %d", getSequence());
+  mylog(DUMP, "ICMP Header :");
+  mylog(DUMP, "type                = %s", getTypeDesc());
+  mylog(DUMP, "code                = %s", getCodeDesc());
+  mylog(DUMP, "checksum            = %d", getChecksum());
+  mylog(DUMP, "identifier          = %d", getIdentifier());
+  mylog(DUMP, "sequence            = %d", getSequence());
 }
 
 /**
@@ -254,7 +254,7 @@ ICMPHeader::dump () {
  */
 void
 ICMPHeader::dumpRaw () {
-  log(DUMP, "ICMP Header :\n");
+  mylog(DUMP, "ICMP Header :\n");
   dumpRawData(WARN, header, header_len);
 }
 
