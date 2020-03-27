$NetBSD: patch-src_UDPProbe.cc,v 1.1 2020/03/27 20:52:19 joerg Exp $

--- src/UDPProbe.cc.orig	2020-03-27 18:20:27.983407363 +0000
+++ src/UDPProbe.cc
@@ -143,7 +143,7 @@ UDPProbe::UDPProbe (const char* src_addr
   uint8* d = new uint8[data_len];
   memset(d, 0, data_len);
 #ifndef DEVANOMALIES
-	//log(WARN, "desactivated ID in UDP DATA");
+	//mylog(WARN, "desactivated ID in UDP DATA");
   memcpy(d, &id, 2);
 #endif
   setData(d, data_len);
@@ -244,10 +244,10 @@ UDPProbe::getID () {
  */
 void
 UDPProbe::dump () {
-  log(DUMP, "==> UDP Probe :");
+  mylog(DUMP, "==> UDP Probe :");
   for (int i = 0; i  < getNbrHeaders(); i++)
     getHeader(i)->dump();
-  log(DUMP, "Data :");
+  mylog(DUMP, "Data :");
   if (data != NULL)
     dumpRawData(DUMP, data, data_length);
 }
@@ -260,7 +260,7 @@ UDPProbe::dumpRaw () {
   uint8* data;
   int   length;
   getDatagram(&data, &length);
-  log(DUMP, "==> UDP Probe :");
+  mylog(DUMP, "==> UDP Probe :");
   dumpRawData(DUMP, data, length);
 }
 
