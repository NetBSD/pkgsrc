$NetBSD: patch-src_findlib_attribs.c,v 1.3 2022/10/06 02:58:17 markd Exp $

use intmax_t instead of int64_t

--- src/findlib/attribs.c.orig	2022-08-05 15:13:35.000000000 +0000
+++ src/findlib/attribs.c
@@ -415,7 +415,7 @@ void encode_stat(char *buf, struct stat 
 int decode_stat(char *buf, struct stat *statp, int stat_size, int32_t *LinkFI)
 {
    char *p = buf;
-   int64_t val;
+   intmax_t val;
    int data_stream;
 
    /*
@@ -519,7 +519,7 @@ int decode_stat(char *buf, struct stat *
 int32_t decode_LinkFI(char *buf, struct stat *statp, int stat_size)
 {
    char *p = buf;
-   int64_t val;
+   intmax_t val;
    /*
     * We store into the stat packet so make sure the caller's conception
     *  is the same as ours.  They can be different if LARGEFILE is not
@@ -824,7 +824,7 @@ int encode_attribsEx(JCR *jcr, char *att
 static bool set_win32_attributes(JCR *jcr, ATTR *attr, BFILE *ofd)
 {
    char *p = attr->attrEx;
-   int64_t val;
+   intmax_t val;
    WIN32_FILE_ATTRIBUTE_DATA atts;
    ULARGE_INTEGER li;
 
