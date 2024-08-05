$NetBSD: patch-globals.h,v 1.1 2024/08/05 09:03:00 tnn Exp $

Match return type of get_crc_table() from zlib.h.
Without it we get an error with GCC 14.
This looks somewhat sketchy but make test succeeds,
and 32-bit is the correct width for the crc32 table, so ...

extract.c:363:25: error: assignment to 'const ulg *' {aka 'const long unsigned int *'} from incompatible pointer type 'const z_crc_t *' {aka 'const unsigned int *'} [-Wincompatible-pointer-types]
363 |         if ((CRC_32_TAB = get_crc_table()) == NULL) {

--- globals.h.orig	2024-08-05 10:40:15.418511764 +0000
+++ globals.h
@@ -226,7 +226,7 @@ typedef struct Globals {
 #if (!defined(USE_ZLIB) || defined(USE_OWN_CRCTAB))
     ZCONST ulg near *crc_32_tab;
 #else
-    ZCONST ulg Far *crc_32_tab;
+    ZCONST z_crc_t Far *crc_32_tab;
 #endif
     ulg       crc32val;             /* CRC shift reg. (was static in funzip) */
 
