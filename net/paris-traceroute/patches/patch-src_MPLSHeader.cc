$NetBSD: patch-src_MPLSHeader.cc,v 1.1 2020/03/27 20:52:19 joerg Exp $

--- src/MPLSHeader.cc.orig	2020-03-27 18:19:50.848849889 +0000
+++ src/MPLSHeader.cc
@@ -14,7 +14,7 @@ MPLSHeader::MPLSHeader(const uint8* data
   int nbr_entries;
   uint32 label;
 
-  log(INFO, "MPLSHeader %d %d", length, offset);
+  mylog(INFO, "MPLSHeader %d %d", length, offset);
   
   header = new uint8[length];
   header_len = length;
@@ -26,7 +26,7 @@ MPLSHeader::MPLSHeader(const uint8* data
 
   if (header[0]>>4 != 2) {
     nbrLabels = 0;
-    log(WARN, "MPLS version %d", header[0]>>4);
+    mylog(WARN, "MPLS version %d", header[0]>>4);
   } else {
     i = 4;
 
@@ -61,7 +61,7 @@ MPLSHeader::MPLSHeader(const uint8* data
     }
   }
   
-  log(INFO, "MPLSHeader fin");
+  mylog(INFO, "MPLSHeader fin");
 }
 
 MPLSHeader::~MPLSHeader () {
@@ -170,7 +170,7 @@ MPLSHeader::pack (uint8* data, int lengt
  */
 void
 MPLSHeader::dump () {
-  log(DUMP, "MPLS Header");
+  mylog(DUMP, "MPLS Header");
   // xxx
 }
 
@@ -179,7 +179,7 @@ MPLSHeader::dump () {
  */
 void
 MPLSHeader::dumpRaw () {
-  log(DUMP, "MPLS Header :\n");
+  mylog(DUMP, "MPLS Header :\n");
   dumpRawData(DUMP, header, header_len);
   // xxx
 }
