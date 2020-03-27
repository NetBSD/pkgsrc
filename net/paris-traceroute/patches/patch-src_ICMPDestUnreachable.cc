$NetBSD: patch-src_ICMPDestUnreachable.cc,v 1.1 2020/03/27 20:52:19 joerg Exp $

--- src/ICMPDestUnreachable.cc.orig	2020-03-27 18:19:31.352092281 +0000
+++ src/ICMPDestUnreachable.cc
@@ -82,14 +82,14 @@ ICMPDestUnreachable::getHeaderLength () 
  */
 void
 ICMPDestUnreachable::dump () {
-  log(DUMP, "ICMP Time Exceeded Header :\n");
-  log(DUMP, "type                = %s\n", getTypeDesc());
-  log(DUMP, "code                = %s\n", getCodeDesc());
-  log(DUMP, "checksum            = %d\n", getChecksum());
-  log(DUMP, "bytes 4-7           = 0x%x\n", *(uint32*)(header+4));
-  log(DUMP, "Erroneous IP4 header :\n");
+  mylog(DUMP, "ICMP Time Exceeded Header :\n");
+  mylog(DUMP, "type                = %s\n", getTypeDesc());
+  mylog(DUMP, "code                = %s\n", getCodeDesc());
+  mylog(DUMP, "checksum            = %d\n", getChecksum());
+  mylog(DUMP, "bytes 4-7           = 0x%x\n", *(uint32*)(header+4));
+  mylog(DUMP, "Erroneous IP4 header :\n");
   ip4_err->dump();
-  log(DUMP, "Erroneous data :\n");
+  mylog(DUMP, "Erroneous data :\n");
   dumpRawData(DUMP, data_err, 8);
 }
 
