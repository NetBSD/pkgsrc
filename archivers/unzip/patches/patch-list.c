$NetBSD: patch-list.c,v 1.1.16.1 2017/02/06 09:10:46 bsiegert Exp $

chunk 1:
Big-hammer fix for
http://seclists.org/oss-sec/2014/q4/497

chunk 2:
CVE-2014-9913 fix from
https://people.debian.org/~sanvila/unzip/cve-2014-9913/cve-2014-9913-unzip-buffer-overflow.txt
via
http://www.info-zip.org/phpBB3/viewtopic.php?f=7&t=529

--- list.c.orig	2009-02-08 17:11:34.000000000 +0000
+++ list.c
@@ -116,7 +116,7 @@ int list_files(__G)    /* return PK-type
     ulg acl_size, tot_aclsize=0L, tot_aclfiles=0L;
 #endif
     min_info info;
-    char methbuf[8];
+    char methbuf[80];
     static ZCONST char dtype[]="NXFS";  /* see zi_short() */
     static ZCONST char Far method[NUM_METHODS+1][8] =
         {"Stored", "Shrunk", "Reduce1", "Reduce2", "Reduce3", "Reduce4",
@@ -339,7 +339,14 @@ int list_files(__G)    /* return PK-type
                 G.crec.compression_method == ENHDEFLATED) {
                 methbuf[5] = dtype[(G.crec.general_purpose_bit_flag>>1) & 3];
             } else if (methnum >= NUM_METHODS) {
-                sprintf(&methbuf[4], "%03u", G.crec.compression_method);
+                /* Fix for CVE-2014-9913, similar to CVE-2016-9844.
+                 * Use the old decimal format only for values which fit.
+                 */
+                if (G.crec.compression_method <= 999) {
+                    sprintf( &methbuf[ 4], "%03u", G.crec.compression_method);
+                } else {
+                    sprintf( &methbuf[ 3], "%04X", G.crec.compression_method);
+                }
             }
 
 #if 0       /* GRR/Euro:  add this? */
