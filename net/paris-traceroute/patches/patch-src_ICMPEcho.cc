$NetBSD: patch-src_ICMPEcho.cc,v 1.1 2020/03/27 20:52:19 joerg Exp $

--- src/ICMPEcho.cc.orig	2020-03-27 18:19:34.138799353 +0000
+++ src/ICMPEcho.cc
@@ -91,11 +91,11 @@ ICMPEcho::getHeaderLength () {
  */
 void
 ICMPEcho::dump () {
-  log(DUMP, "ICMP Echo header :\n");
-  log(DUMP, "type                = %s\n", getTypeDesc());
-  log(DUMP, "code                = %s\n", getCodeDesc());
-  log(DUMP, "checksum            = %d\n", getChecksum());
-  log(DUMP, "identifier          = %d\n", getIdentifier());
-  log(DUMP, "sequence            = %d\n", getSequence());
+  mylog(DUMP, "ICMP Echo header :\n");
+  mylog(DUMP, "type                = %s\n", getTypeDesc());
+  mylog(DUMP, "code                = %s\n", getCodeDesc());
+  mylog(DUMP, "checksum            = %d\n", getChecksum());
+  mylog(DUMP, "identifier          = %d\n", getIdentifier());
+  mylog(DUMP, "sequence            = %d\n", getSequence());
 }
 
