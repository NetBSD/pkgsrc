$NetBSD: patch-src_findlib_attribs.c,v 1.1 2012/10/06 17:54:53 christos Exp $

use intmax_t instead of int64_t

--- src/findlib/attribs.c.orig	2012-09-13 04:51:19.000000000 -0400
+++ src/findlib/attribs.c	2012-10-04 23:52:49.000000000 -0400
@@ -288,7 +288,7 @@
 int decode_stat(char *buf, struct stat *statp, int stat_size, int32_t *LinkFI)
 {
    char *p = buf;
-   int64_t val;
+   intmax_t val;
 
    /*
     * We store into the stat packet so make sure the caller's conception
@@ -380,7 +380,7 @@
 int32_t decode_LinkFI(char *buf, struct stat *statp, int stat_size)
 {
    char *p = buf;
-   int64_t val;
+   intmax_t val;
    /*
     * We store into the stat packet so make sure the caller's conception
     *  is the same as ours.  They can be different if LARGEFILE is not
@@ -694,7 +694,7 @@
 static bool set_win32_attributes(JCR *jcr, ATTR *attr, BFILE *ofd)
 {
    char *p = attr->attrEx;
-   int64_t val;
+   intmax_t val;
    WIN32_FILE_ATTRIBUTE_DATA atts;
    ULARGE_INTEGER li;
    POOLMEM *win32_ofile;
