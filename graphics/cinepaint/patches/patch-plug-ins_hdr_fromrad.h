$NetBSD: patch-plug-ins_hdr_fromrad.h,v 1.1 2018/12/31 13:11:12 ryoon Exp $

--- plug-ins/hdr/fromrad.h.orig	2008-05-22 04:20:12.000000000 +0000
+++ plug-ins/hdr/fromrad.h
@@ -103,7 +103,7 @@ extern char  resolu_buf[RESOLU_BUFLEN];
 #define  fprtresolu(sl,ns,fp)	fprintf(fp,PIXSTDFMT,ns,sl)
 #define  fscnresolu(sl,ns,fp)	(fscanf(fp,PIXSTDFMT,ns,sl)==2)
 
-extern char  *fgets(), *resolu2str();
+extern char  *resolu2str();
 
 /* End of resolu.h defs */
 
