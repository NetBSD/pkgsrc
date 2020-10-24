$NetBSD: patch-src_utils_format__kairosdb_format__kairosdb.c,v 1.1 2020/10/24 22:39:45 wiz Exp $

Cast arguments to isalnum() and tolower() to "unsigned char" to
squelch warnings.

--- src/utils/format_kairosdb/format_kairosdb.c.orig	2016-11-30 08:52:01.000000000 +0000
+++ src/utils/format_kairosdb/format_kairosdb.c
@@ -80,9 +80,9 @@ static int kairosdb_escape_string(char *
   /* authorize -_. and alpha num but also escapes " */
   BUFFER_ADD('"');
   for (size_t src_pos = 0; string[src_pos] != 0; src_pos++) {
-    if (isalnum(string[src_pos]) || 0x2d == string[src_pos] ||
+    if (isalnum((unsigned char)string[src_pos]) || 0x2d == string[src_pos] ||
         0x2e == string[src_pos] || 0x5f == string[src_pos])
-      BUFFER_ADD(tolower(string[src_pos]));
+      BUFFER_ADD(tolower((unsigned char)string[src_pos]));
   } /* for */
   BUFFER_ADD('"');
   buffer[dst_pos] = 0;
