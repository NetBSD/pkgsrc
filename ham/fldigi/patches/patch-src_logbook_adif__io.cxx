$NetBSD: patch-src_logbook_adif__io.cxx,v 1.1 2016/12/22 11:38:01 joerg Exp $

--- src/logbook/adif_io.cxx.orig	2016-12-21 10:22:23.131474254 +0000
+++ src/logbook/adif_io.cxx
@@ -311,7 +311,7 @@ void cAdifIO::do_readfile(const char *fn
 			} else {
 				ptr2 = ptr + 1;
 			}
-			if ((ptr2) > 0 && (unsigned)(ptr2 - ptr) <= p)
+			if (ptr2 && (unsigned)(ptr2 - ptr) <= p)
 				ptr = strchr(ptr2,'<');
 			else
 				break; // corrupt record
