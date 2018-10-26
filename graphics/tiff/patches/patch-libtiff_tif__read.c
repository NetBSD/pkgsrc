$NetBSD: patch-libtiff_tif__read.c,v 1.1.2.2 2018/10/26 07:02:56 spz Exp $

And in case libtiff is compiled with CHUNKY_STRIP_READ_SUPPORT, make sure
that whole strip data is provided to JBIGDecode()

Part of commit 681748ec2f5ce88da5f9fa6831e1653e46af8a66 which fixes
CVE-2018-18557

--- libtiff/tif_read.c.orig	2017-11-18 14:42:21.664534434 +0000
+++ libtiff/tif_read.c
@@ -348,6 +348,12 @@ TIFFSeek(TIFF* tif, uint32 row, uint16 s
             return 0;
         whole_strip = tif->tif_dir.td_stripbytecount[strip] < 10
                 || isMapped(tif);
+        if( td->td_compression == COMPRESSION_JBIG )
+        {
+            /* Ideally plugins should have a way to declare they don't support
+             * chunk strip */
+            whole_strip = 1;
+        }
 #else
         whole_strip = 1;
 #endif
