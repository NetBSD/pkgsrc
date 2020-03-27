$NetBSD: patch-src_TCPProbe.cc,v 1.1 2020/03/27 20:52:19 joerg Exp $

--- src/TCPProbe.cc.orig	2020-03-27 18:20:16.329393883 +0000
+++ src/TCPProbe.cc
@@ -132,10 +132,10 @@ TCPProbe::getID () {
 
 void
 TCPProbe::dump () {
-  log(DUMP, "==> TCP Probe :");
+  mylog(DUMP, "==> TCP Probe :");
   for (int i = 0; i  < getNbrHeaders(); i++)
     getHeader(i)->dump();
-  log(DUMP, "Data :");
+  mylog(DUMP, "Data :");
   if (data != NULL)
     dumpRawData(DUMP, data, data_length);
 }
@@ -145,7 +145,7 @@ TCPProbe::dumpRaw () {
   uint8* data;
   int   length;
   getDatagram(&data, &length);
-  log(DUMP, "==> TCP Probe :");
+  mylog(DUMP, "==> TCP Probe :");
   dumpRawData(DUMP, data, length);
 }
 
