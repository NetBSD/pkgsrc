$NetBSD: patch-libtiff_tif_dir.h,v 1.3 2017/06/21 02:47:45 pgoyette Exp $

fix CVE-2014-8128, CVE-2016-5318, CVE-2015-7554 & CVE-2016-10095
per http://bugzilla.maptools.org/show_bug.cgi?id=2580

also CVE-2017-9147
(http://bugzilla.maptools.org/show_bug.cgi?id=2693)


Index: tif_dir.h
===================================================================
RCS file: /cvs/maptools/cvsroot/libtiff/libtiff/tif_dir.h,v
retrieving revision 1.54
retrieving revision 1.55
diff -w -u -b -r1.54 -r1.55
--- libtiff/tif_dir.h.orig	18 Feb 2011 20:53:05 -0000	1.54
+++ libtiff/tif_dir.h	1 Jun 2017 12:44:04 -0000	1.55
@@ -291,6 +291,7 @@
 extern int _TIFFMergeFields(TIFF*, const TIFFField[], uint32);
 extern const TIFFField* _TIFFFindOrRegisterField(TIFF *, uint32, TIFFDataType);
 extern  TIFFField* _TIFFCreateAnonField(TIFF *, uint32, TIFFDataType);
+extern int _TIFFCheckFieldIsValidForCodec(TIFF *tif, ttag_t tag);
 
 #if defined(__cplusplus)
 }
