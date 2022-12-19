$NetBSD: patch-cfs__fh.c,v 1.1 2022/12/19 23:18:37 gdt Exp $

--- cfs_fh.c.orig	2013-05-15 16:50:30.000000000 +0000
+++ cfs_fh.c
@@ -492,7 +492,9 @@ fhtofd(cfs_fileid *f, int mode)
 		openfd=NULL;
 	}
 
+#if 0
 	if (mode==0) { mode=CFS_WRITE; }
+#endif
 	/* Phil Karn's hack for R/O file systems */
 	if ((fd=open(f->name,mode,0))<0 && errno == EROFS) {
 		mode = CFS_READ;        /* Force read and try again */
