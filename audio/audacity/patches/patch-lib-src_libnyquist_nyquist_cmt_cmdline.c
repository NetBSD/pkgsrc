$NetBSD: patch-lib-src_libnyquist_nyquist_cmt_cmdline.c,v 1.1 2025/09/29 20:52:03 mrg Exp $

Fix ctype-abuse.

--- lib-src/libnyquist/nyquist/cmt/cmdline.c.orig	2020-05-19 02:43:53.000000000 -0700
+++ lib-src/libnyquist/nyquist/cmt/cmdline.c	2025-09-25 13:16:00.064742864 -0700
@@ -377,10 +377,10 @@
         while (*syntax_ptr != EOS) {
             register char *s_ptr = s;
             while (*syntax_ptr != EOS &&
-                   !(isalnum(*syntax_ptr))) syntax_ptr++;
+                   !(isalnum((unsigned char)*syntax_ptr))) syntax_ptr++;
             while (*s_ptr != EOS && (*s_ptr++ == *syntax_ptr))
                 syntax_ptr++; /* only increment if there's a match */
-            if (!(isalnum(*s_ptr)) && *syntax_ptr == '<') {
+            if (!(isalnum((unsigned char)*s_ptr)) && *syntax_ptr == '<') {
                 syntax_ptr++; /* advance to the type field */
                 if (*syntax_ptr == 's') return cl_SW;
                 if (*syntax_ptr != 'o') 
@@ -402,7 +402,7 @@
         char *syntax_ptr = syntax[i];
         while (*syntax_ptr != EOS) {
             while (*syntax_ptr != EOS &&
-                   !(isalnum(*syntax_ptr))) syntax_ptr++;
+                   !(isalnum((unsigned char)*syntax_ptr))) syntax_ptr++;
             if (s[0] == *syntax_ptr) {
                 if (found_it) return FALSE;     /* ambiguous */
                 /* else, find the type */
