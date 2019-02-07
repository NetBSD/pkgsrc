$NetBSD: patch-src_findlib_attribs.c,v 1.2 2019/02/07 11:29:31 markd Exp $

use intmax_t instead of int64_t

--- src/findlib/attribs.c.orig	2018-12-21 08:40:51.000000000 +0000
+++ src/findlib/attribs.c
@@ -410,7 +410,7 @@ void encode_stat(char *buf, struct stat 
 int decode_stat(char *buf, struct stat *statp, int stat_size, int32_t *LinkFI)
 {
    char *p = buf;
-   int64_t val;
+   intmax_t val;
    int data_stream;
 
    /*
@@ -514,7 +514,7 @@ int decode_stat(char *buf, struct stat *
 int32_t decode_LinkFI(char *buf, struct stat *statp, int stat_size)
 {
    char *p = buf;
-   int64_t val;
+   intmax_t val;
    /*
     * We store into the stat packet so make sure the caller's conception
     *  is the same as ours.  They can be different if LARGEFILE is not
@@ -822,7 +822,7 @@ int encode_attribsEx(JCR *jcr, char *att
 static bool set_win32_attributes(JCR *jcr, ATTR *attr, BFILE *ofd)
 {
    char *p = attr->attrEx;
-   int64_t val;
+   intmax_t val;
    WIN32_FILE_ATTRIBUTE_DATA atts;
    ULARGE_INTEGER li;
    POOLMEM *win32_ofile;
