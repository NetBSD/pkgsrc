$NetBSD: patch-src_devices_dev__wdc.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/devices/dev_wdc.cc.orig	2014-08-17 08:45:12.000000000 +0000
+++ src/devices/dev_wdc.cc
@@ -580,13 +580,13 @@ DEVICE_ACCESS(wdc)
 			}
 
 			if (d->data_debug) {
-				const char *s = "0x%04"PRIx64" ]\n";
+				const char *s = "0x%04" PRIx64 " ]\n";
 				if (len == 1)
-					s = "0x%02"PRIx64" ]\n";
+					s = "0x%02" PRIx64 " ]\n";
 				if (len == 4)
-					s = "0x%08"PRIx64" ]\n";
+					s = "0x%08" PRIx64 " ]\n";
 				if (len == 8)
-					s = "0x%016"PRIx64" ]\n";
+					s = "0x%016" PRIx64 " ]\n";
 				debug("[ wdc: read from DATA: ");
 				debug(s, (uint64_t) odata);
 			}
@@ -621,13 +621,13 @@ DEVICE_ACCESS(wdc)
 		} else {
 			int inbuf_len;
 			if (d->data_debug) {
-				const char *s = "0x%04"PRIx64" ]\n";
+				const char *s = "0x%04" PRIx64 " ]\n";
 				if (len == 1)
-					s = "0x%02"PRIx64" ]\n";
+					s = "0x%02" PRIx64 " ]\n";
 				if (len == 4)
-					s = "0x%08"PRIx64" ]\n";
+					s = "0x%08" PRIx64 " ]\n";
 				if (len == 8)
-					s = "0x%016"PRIx64" ]\n";
+					s = "0x%016" PRIx64 " ]\n";
 				debug("[ wdc: write to DATA: ");
 				debug(s, (uint64_t) idata);
 			}
@@ -960,4 +960,3 @@ DEVINIT(wdc)
 
 	return 1;
 }
-
