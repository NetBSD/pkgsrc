$NetBSD: patch-src_utils__format__kairosdb.c,v 1.2 2016/12/07 17:28:39 fhajny Exp $

--- src/utils_format_kairosdb.c.orig	2016-11-30 08:52:01.332909704 +0000
+++ src/utils_format_kairosdb.c
@@ -80,9 +80,9 @@ static int kairosdb_escape_string(char *
   /* authorize -_. and alpha num but also escapes " */
   BUFFER_ADD('"');
   for (size_t src_pos = 0; string[src_pos] != 0; src_pos++) {
-    if (isalnum(string[src_pos]) || 0x2d == string[src_pos] ||
+    if ((unsigned char)isalnum(string[src_pos]) || 0x2d == string[src_pos] ||
         0x2e == string[src_pos] || 0x5f == string[src_pos])
-      BUFFER_ADD(tolower(string[src_pos]));
+      BUFFER_ADD(tolower((unsigned char)string[src_pos]));
   } /* for */
   BUFFER_ADD('"');
   buffer[dst_pos] = 0;
