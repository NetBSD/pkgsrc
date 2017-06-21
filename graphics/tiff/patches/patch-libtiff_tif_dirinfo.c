$NetBSD: patch-libtiff_tif_dirinfo.c,v 1.3 2017/06/21 02:47:45 pgoyette Exp $

fix CVE-2014-8128, CVE-2016-5318, CVE-2015-7554 & CVE-2016-10095
per http://bugzilla.maptools.org/show_bug.cgi?id=2580

also CVE-2017-9147 
(http://bugzilla.maptools.org/show_bug.cgi?id=2693)


Index: tif_dirinfo.c
===================================================================
RCS file: /cvs/maptools/cvsroot/libtiff/libtiff/tif_dirinfo.c,v
retrieving revision 1.126
retrieving revision 1.127
diff -w -u -b -r1.126 -r1.127
--- libtiff/tif_dirinfo.c.orig	18 Nov 2016 02:52:13 -0000	1.126
+++ libtiff/tif_dirinfo.c	1 Jun 2017 12:44:04 -0000	1.127
@@ -956,6 +956,109 @@
 	return 0;
 }
 
+int
+_TIFFCheckFieldIsValidForCodec(TIFF *tif, ttag_t tag)
+{
+	/* Filter out non-codec specific tags */
+	switch (tag) {
+	    /* Shared tags */
+	    case TIFFTAG_PREDICTOR:
+	    /* JPEG tags */
+	    case TIFFTAG_JPEGTABLES:
+	    /* OJPEG tags */
+	    case TIFFTAG_JPEGIFOFFSET:
+	    case TIFFTAG_JPEGIFBYTECOUNT:
+	    case TIFFTAG_JPEGQTABLES:
+	    case TIFFTAG_JPEGDCTABLES:
+	    case TIFFTAG_JPEGACTABLES:
+	    case TIFFTAG_JPEGPROC:
+	    case TIFFTAG_JPEGRESTARTINTERVAL:
+	    /* CCITT* */
+	    case TIFFTAG_BADFAXLINES:
+	    case TIFFTAG_CLEANFAXDATA:
+	    case TIFFTAG_CONSECUTIVEBADFAXLINES:
+	    case TIFFTAG_GROUP3OPTIONS:
+	    case TIFFTAG_GROUP4OPTIONS:
+		break;
+	    default:
+		return 1;
+	}
+	/* Check if codec specific tags are allowed for the current
+	 * compression scheme (codec) */
+	switch (tif->tif_dir.td_compression) {
+	    case COMPRESSION_LZW:
+		if (tag == TIFFTAG_PREDICTOR)
+		    return 1;
+		break;
+	    case COMPRESSION_PACKBITS:
+		/* No codec-specific tags */
+		break;
+	    case COMPRESSION_THUNDERSCAN:
+		/* No codec-specific tags */
+		break;
+	    case COMPRESSION_NEXT:
+		/* No codec-specific tags */
+		break;
+	    case COMPRESSION_JPEG:
+		if (tag == TIFFTAG_JPEGTABLES)
+		    return 1;
+		break;
+	    case COMPRESSION_OJPEG:
+		switch (tag) {
+		    case TIFFTAG_JPEGIFOFFSET:
+		    case TIFFTAG_JPEGIFBYTECOUNT:
+		    case TIFFTAG_JPEGQTABLES:
+		    case TIFFTAG_JPEGDCTABLES:
+		    case TIFFTAG_JPEGACTABLES:
+		    case TIFFTAG_JPEGPROC:
+		    case TIFFTAG_JPEGRESTARTINTERVAL:
+			return 1;
+		}
+		break;
+	    case COMPRESSION_CCITTRLE:
+	    case COMPRESSION_CCITTRLEW:
+	    case COMPRESSION_CCITTFAX3:
+	    case COMPRESSION_CCITTFAX4:
+		switch (tag) {
+		    case TIFFTAG_BADFAXLINES:
+		    case TIFFTAG_CLEANFAXDATA:
+		    case TIFFTAG_CONSECUTIVEBADFAXLINES:
+			return 1;
+		    case TIFFTAG_GROUP3OPTIONS:
+			if (tif->tif_dir.td_compression == COMPRESSION_CCITTFAX3)
+			    return 1;
+			break;
+		    case TIFFTAG_GROUP4OPTIONS:
+			if (tif->tif_dir.td_compression == COMPRESSION_CCITTFAX4)
+			    return 1;
+			break;
+		}
+		break;
+	    case COMPRESSION_JBIG:
+		/* No codec-specific tags */
+		break;
+	    case COMPRESSION_DEFLATE:
+	    case COMPRESSION_ADOBE_DEFLATE:
+		if (tag == TIFFTAG_PREDICTOR)
+		    return 1;
+		break;
+	   case COMPRESSION_PIXARLOG:
+		if (tag == TIFFTAG_PREDICTOR)
+		    return 1;
+		break;
+	    case COMPRESSION_SGILOG:
+	    case COMPRESSION_SGILOG24:
+		/* No codec-specific tags */
+		break;
+	    case COMPRESSION_LZMA:
+		if (tag == TIFFTAG_PREDICTOR)
+		    return 1;
+		break;
+
+	}
+	return 0;
+}
+
 /* vim: set ts=8 sts=8 sw=8 noet: */
 
 /*
