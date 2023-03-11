$NetBSD: patch-cfs__fh.c,v 1.2 2023/03/11 01:54:01 gdt Exp $

If a file was opened for reading, do not open the ciphertext in RW
mode.  While in many filesystems, opening a file for writing and not
writing does not result in a modification, coda does a writeback in
that case.  Plus, as a general matter, reads should only lead to
reads.  Details available at
  https://gnats.netbsd.org/28479

\todo File and discuss upstream.

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
