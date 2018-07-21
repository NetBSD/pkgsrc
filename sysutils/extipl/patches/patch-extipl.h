$NetBSD: patch-extipl.h,v 1.1 2018/07/21 21:08:03 maya Exp $

64bit support

--- extipl.h.orig	2002-03-25 22:48:52.000000000 +0900
+++ extipl.h
@@ -5,4 +5,6 @@
  */
 
+#include <stdint.h>
+
 #define VERSION			"5.04"
 #define DATE			"2002/03/26"
@@ -40,5 +42,5 @@
 
 typedef unsigned char byte;
-typedef unsigned long long ul_long;
+typedef uint64_t ul_long;
 
 typedef struct hdadr_s {
@@ -53,6 +55,6 @@ typedef struct partition_s {
 	byte	       sysind;
 	hdadr_s        end_chs;
-	unsigned long  sector_offset;
-	unsigned long  nr_sector;
+	uint32_t       sector_offset;
+	uint32_t       nr_sector;
     } partition_s;
 
