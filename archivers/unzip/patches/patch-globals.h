$NetBSD: patch-globals.h,v 1.2 2025/08/24 16:58:07 kikadf Exp $

Match return type of get_crc_table() from zlib.h.
Without it we get an error with GCC 14.
This looks somewhat sketchy but make test succeeds,
and 32-bit is the correct width for the crc32 table, so ...

extract.c:363:25: error: assignment to 'const ulg *' {aka 'const long unsigned int *'} from incompatible pointer type 'const z_crc_t *' {aka 'const unsigned int *'} [-Wincompatible-pointer-types]
363 |         if ((CRC_32_TAB = get_crc_table()) == NULL) {

Fix CVE-2019-13232
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part1.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part2.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part3.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-manpage.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part4.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part5.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part6.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-switch.patch


--- globals.h.orig	2009-02-22 20:25:04.000000000 +0100
+++ globals.h
@@ -226,7 +226,7 @@ typedef struct Globals {
 #if (!defined(USE_ZLIB) || defined(USE_OWN_CRCTAB))
     ZCONST ulg near *crc_32_tab;
 #else
-    ZCONST ulg Far *crc_32_tab;
+    ZCONST z_crc_t Far *crc_32_tab;
 #endif
     ulg       crc32val;             /* CRC shift reg. (was static in funzip) */
 
@@ -266,6 +266,7 @@ typedef struct Globals {
     int      reported_backslash;   /* extract.c static */
     int      disk_full;
     int      newfile;
+    void     **cover;              /* used in extract.c for bomb detection */
 
     int      didCRlast;            /* fileio static */
     ulg      numlines;             /* fileio static: number of lines printed */
