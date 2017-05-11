$NetBSD: patch-libtiff_tif__strip.c,v 1.1.2.2 2017/05/11 17:47:20 bsiegert Exp $

Fix CVE-2016-10270, ref.
http://bugzilla.maptools.org/show_bug.cgi?id=2608
https://github.com/vadz/libtiff/commit/9a72a69e035ee70ff5c41541c8c61cd97990d018

--- libtiff/tif_strip.c.orig	2016-11-10 02:12:36.000000000 +0000
+++ libtiff/tif_strip.c
@@ -63,15 +63,6 @@ TIFFNumberOfStrips(TIFF* tif)
 	TIFFDirectory *td = &tif->tif_dir;
 	uint32 nstrips;
 
-    /* If the value was already computed and store in td_nstrips, then return it,
-       since ChopUpSingleUncompressedStrip might have altered and resized the
-       since the td_stripbytecount and td_stripoffset arrays to the new value
-       after the initial affectation of td_nstrips = TIFFNumberOfStrips() in
-       tif_dirread.c ~line 3612.
-       See http://bugzilla.maptools.org/show_bug.cgi?id=2587 */
-    if( td->td_nstrips )
-        return td->td_nstrips;
-
 	nstrips = (td->td_rowsperstrip == (uint32) -1 ? 1 :
 	     TIFFhowmany_32(td->td_imagelength, td->td_rowsperstrip));
 	if (td->td_planarconfig == PLANARCONFIG_SEPARATE)
