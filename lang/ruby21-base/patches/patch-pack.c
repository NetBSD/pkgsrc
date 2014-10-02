$NetBSD: patch-pack.c,v 1.2 2014/10/02 08:59:52 taca Exp $

Fix for CVE-2014-4975 from revision #46806 in ruby_2_1 branch.

--- pack.c.orig	2013-11-08 02:37:47.000000000 +0000
+++ pack.c
@@ -946,7 +946,8 @@ static const char b64_table[] =
 static void
 encodes(VALUE str, const char *s, long len, int type, int tail_lf)
 {
-    char buff[4096];
+    enum {buff_size = 4096, encoded_unit = 4};
+    char buff[buff_size + 1];	/* +1 for tail_lf */
     long i = 0;
     const char *trans = type == 'u' ? uu_table : b64_table;
     char padding;
@@ -959,7 +960,7 @@ encodes(VALUE str, const char *s, long l
 	padding = '=';
     }
     while (len >= 3) {
-        while (len >= 3 && sizeof(buff)-i >= 4) {
+        while (len >= 3 && buff_size-i >= encoded_unit) {
             buff[i++] = trans[077 & (*s >> 2)];
             buff[i++] = trans[077 & (((*s << 4) & 060) | ((s[1] >> 4) & 017))];
             buff[i++] = trans[077 & (((s[1] << 2) & 074) | ((s[2] >> 6) & 03))];
@@ -967,7 +968,7 @@ encodes(VALUE str, const char *s, long l
             s += 3;
             len -= 3;
         }
-        if (sizeof(buff)-i < 4) {
+        if (buff_size-i < encoded_unit) {
             rb_str_buf_cat(str, buff, i);
             i = 0;
         }
@@ -987,6 +988,7 @@ encodes(VALUE str, const char *s, long l
     }
     if (tail_lf) buff[i++] = '\n';
     rb_str_buf_cat(str, buff, i);
+    if ((size_t)i > sizeof(buff)) rb_bug("encodes() buffer overrun");
 }
 
 static const char hex_table[] = "0123456789ABCDEF";
