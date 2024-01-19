$NetBSD: patch-src_hu__lib.c,v 1.1 2024/01/19 13:02:59 micha Exp $

Fix namespace clash on SmartOS.

Names with suffix "_t" are reserved for all POSIX headers:
<https://pubs.opengroup.org/onlinepubs/9699919799/functions/V2_chap02.html#tag_15_02_02>
(Woof indirectly includes "string.h")

--- src/hu_lib.c.orig	2023-12-13 09:45:57.000000000 +0000
+++ src/hu_lib.c
@@ -51,7 +51,7 @@ typedef enum {
     offset_bottomright,
 
     num_offsets,
-} offset_t;
+} woof_offset_type;
 
 static int align_offset[num_offsets];
 
