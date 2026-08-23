$NetBSD: patch-unlzh.c,v 1.1 2026/08/23 18:46:55 wiz Exp $

CVE-2026-41992 gzip 1.14 out-of-bounds memory buffer access
https://www.openwall.com/lists/oss-security/2026/08/23/1

--- unlzh.c.orig	2024-08-09 22:06:03.000000000 +0000
+++ unlzh.c
@@ -307,6 +307,12 @@ huf_decode_start ()
 static void
 huf_decode_start ()
 {
+    /* Needed in case LEFT and RIGHT are reused from a previous
+       LZW decompression.  It may be overkill to clear all of both
+       arrays, but nobody has had time to analyze this carefully.  */
+    memzero (left, (2 * NC - 1) * sizeof *left);
+    memzero (right, (2 * NC - 1) * sizeof *right);
+
     init_getbits();  blocksize = 0;
 }
 
