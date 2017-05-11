$NetBSD: patch-libtiff_tif__pixarlog.c,v 1.1.2.2 2017/05/11 17:47:20 bsiegert Exp $

Fix CVE-2016-10269, ref. http://bugzilla.maptools.org/show_bug.cgi?id=2604
and
https://github.com/vadz/libtiff/commit/1044b43637fa7f70fb19b93593777b78bd20da86

--- libtiff/tif_pixarlog.c.orig	2016-09-23 22:56:06.000000000 +0000
+++ libtiff/tif_pixarlog.c
@@ -1233,8 +1233,10 @@ PixarLogPostEncode(TIFF* tif)
 static void
 PixarLogClose(TIFF* tif)
 {
+	PixarLogState* sp = (PixarLogState*) tif->tif_data;
 	TIFFDirectory *td = &tif->tif_dir;
 
+	assert(sp != 0);
 	/* In a really sneaky (and really incorrect, and untruthful, and
 	 * troublesome, and error-prone) maneuver that completely goes against
 	 * the spirit of TIFF, and breaks TIFF, on close, we covertly
@@ -1243,8 +1245,19 @@ PixarLogClose(TIFF* tif)
 	 * readers that don't know about PixarLog, or how to set
 	 * the PIXARLOGDATFMT pseudo-tag.
 	 */
-	td->td_bitspersample = 8;
-	td->td_sampleformat = SAMPLEFORMAT_UINT;
+
+	if (sp->state&PLSTATE_INIT) {
+	    /* We test the state to avoid an issue such as in
+	     * http://bugzilla.maptools.org/show_bug.cgi?id=2604
+	     * What appends in that case is that the bitspersample is 1 and
+	     * a TransferFunction is set. The size of the TransferFunction
+	     * depends on 1<<bitspersample. So if we increase it, an access
+	     * out of the buffer will happen at directory flushing.
+	     * Another option would be to clear those targs. 
+	     */
+	    td->td_bitspersample = 8;
+	    td->td_sampleformat = SAMPLEFORMAT_UINT;
+	}
 }
 
 static void
