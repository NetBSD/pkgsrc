$NetBSD: patch-libtiff_tif_dirread.c,v 1.7 2017/06/21 02:47:45 pgoyette Exp $

fix CVE-2014-8128, CVE-2016-5318, CVE-2015-7554 & CVE-2016-10095
per http://bugzilla.maptools.org/show_bug.cgi?id=2580

also CVE-2017-9147 
(http://bugzilla.maptools.org/show_bug.cgi?id=2693)


Index: tif_dirread.c
===================================================================
RCS file: /cvs/maptools/cvsroot/libtiff/libtiff/tif_dirread.c,v
retrieving revision 1.208
retrieving revision 1.209
diff -w -u -b -r1.208 -r1.209
--- libtiff/tif_dirread.c.orig	27 Apr 2017 15:46:22 -0000	1.208
+++ libtiff/tif_dirread.c	1 Jun 2017 12:44:04 -0000	1.209
@@ -3580,6 +3580,10 @@
 							goto bad;
 						dp->tdir_tag=IGNORE;
 						break;
+                                        default:
+                                            if( !_TIFFCheckFieldIsValidForCodec(tif, dp->tdir_tag) )
+                                                dp->tdir_tag=IGNORE;
+                                            break;
 				}
 			}
 		}
