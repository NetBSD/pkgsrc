$NetBSD: patch-avilib_avidump.c,v 1.1 2015/11/21 17:14:26 adam Exp $

Compatibility fix.

--- avilib/avidump.c.orig	2012-02-01 17:07:24.000000000 +0000
+++ avilib/avidump.c
@@ -320,7 +320,7 @@ static void dump_vals(int fd, int count,
 {
     uint32_t i,j,val32;
     uint16_t val16;
-    loff_t val64;
+    uint64_t val64;
     char val8;
 
     for (i = 0; names[i].type != EoLST; i++) {
@@ -605,7 +605,7 @@ static boolean ProcessChunk(int fd, off_
 
     case indxtag: {
 	uint32_t chunks=*chunksize-sizeof(names_indx)/sizeof(char*);
-	loff_t offset;
+	uint64_t offset;
 	uint32_t size, duration;
 	uint32_t u=0;
 	off_t indxend = datapos + chunks;
