$NetBSD: patch-grep.h,v 1.1 2015/07/09 10:56:54 jperkin Exp $

Update zlib API.

--- grep.h.orig	2007-12-06 05:37:06.000000000 +0000
+++ grep.h
@@ -129,6 +129,6 @@ void grep_close(file_t *f);
 
 /* binary.c */
 int bin_file(FILE * f);
-int gzbin_file(gzFile * f);
+int gzbin_file(gzFile f);
 int mmbin_file(mmf_t *f);
 
