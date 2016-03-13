$NetBSD: patch-src_libjasper_base_jas__icc.c,v 1.1 2016/03/13 04:11:18 tnn Exp $

CVE-2016-1577 prevent double free. Via Debian.
CVE-2016-2116 memory leak / DoS. Via Debian.

--- src/libjasper/base/jas_icc.c.orig	2016-03-13 04:09:54.821655643 +0000
+++ src/libjasper/base/jas_icc.c
@@ -300,6 +300,7 @@ jas_iccprof_t *jas_iccprof_load(jas_stre
 				if (jas_iccprof_setattr(prof, tagtabent->tag, attrval))
 					goto error;
 				jas_iccattrval_destroy(attrval);
+				attrval = 0;
 			} else {
 #if 0
 				jas_eprintf("warning: skipping unknown tag type\n");
@@ -1699,6 +1700,8 @@ jas_iccprof_t *jas_iccprof_createfrombuf
 	jas_stream_close(in);
 	return prof;
 error:
+	if (in)
+		jas_stream_close(in);
 	return 0;
 }
 
