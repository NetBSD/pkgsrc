$NetBSD: patch-src_utils__format__kairosdb.c,v 1.1 2016/11/20 22:11:28 joerg Exp $

--- src/utils_format_kairosdb.c.orig	2016-11-19 12:00:24.000000000 +0000
+++ src/utils_format_kairosdb.c
@@ -83,11 +83,11 @@ static int kairosdb_escape_string (char 
   BUFFER_ADD ('"');
   for (size_t src_pos = 0; string[src_pos] != 0; src_pos++)
   {
-    if (isalnum(string[src_pos]) ||
+    if (isalnum((unsigned char)string[src_pos]) ||
       0x2d == string[src_pos] ||
       0x2e == string[src_pos] ||
       0x5f == string[src_pos])
-        BUFFER_ADD (tolower(string[src_pos]));
+        BUFFER_ADD (tolower((unsigned char)string[src_pos]));
   } /* for */
   BUFFER_ADD ('"');
   buffer[dst_pos] = 0;
