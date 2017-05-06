$NetBSD: patch-libtiff_tif_getimage.c,v 1.1.2.2 2017/05/06 15:01:21 bsiegert Exp $

https://nvd.nist.gov/vuln/detail/CVE-2017-7592
http://bugzilla.maptools.org/show_bug.cgi?id=2658
https://github.com/vadz/libtiff/commit/48780b4fcc42

--- libtiff/tif_getimage.c.orig	2016-11-18 02:47:45.000000000 +0000
+++ libtiff/tif_getimage.c
@@ -1305,7 +1305,7 @@ DECLAREContigPutFunc(putagreytile)
     while (h-- > 0) {
 	for (x = w; x-- > 0;)
         {
-            *cp++ = BWmap[*pp][0] & (*(pp+1) << 24 | ~A1);
+            *cp++ = BWmap[*pp][0] & ((uint32)*(pp+1) << 24 | ~A1);
             pp += samplesperpixel;
         }
 	cp += toskew;
