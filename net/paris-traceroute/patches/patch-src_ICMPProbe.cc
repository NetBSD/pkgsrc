$NetBSD: patch-src_ICMPProbe.cc,v 1.1 2020/03/27 20:52:19 joerg Exp $

--- src/ICMPProbe.cc.orig	2020-03-27 18:19:38.646376189 +0000
+++ src/ICMPProbe.cc
@@ -124,10 +124,10 @@ ICMPProbe::getID () {
  */
 void
 ICMPProbe::dump () {
-  log(DUMP, "==> ICMP Probe :");
+  mylog(DUMP, "==> ICMP Probe :");
   for (int i = 0; i  < getNbrHeaders(); i++)
     getHeader(i)->dump();
-  log(DUMP, "Data :");
+  mylog(DUMP, "Data :");
   if (data != NULL)
     dumpRawData(DUMP, data, data_length);
 }
@@ -140,7 +140,7 @@ ICMPProbe::dumpRaw () {
   uint8* data;
   int   length;
   getDatagram(&data, &length);
-  log(DUMP, "==> ICMP Probe :");
+  mylog(DUMP, "==> ICMP Probe :");
   dumpRawData(DUMP, data, length);
 }
 
