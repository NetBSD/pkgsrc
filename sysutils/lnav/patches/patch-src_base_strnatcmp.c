$NetBSD: patch-src_base_strnatcmp.c,v 1.1 2023/05/24 22:42:53 he Exp $

Ensure argument to isdigit is either "unsigned char" or EOF by casting,
so as to avoid possibly undefined behaviour.

--- ./src/base/strnatcmp.c.orig	2021-08-09 16:59:46.000000000 +0000
+++ ./src/base/strnatcmp.c
@@ -275,13 +275,13 @@ int ipv4cmp(int a_len, nat_char const *a
     }
 
     for (; ai < a_len; ai++) {
-        if (!isdigit(a[ai]) || a[ai] != '.') {
+        if (!isdigit((unsigned char)a[ai]) || a[ai] != '.') {
             return 0;
         }
     }
 
     for (; bi < b_len; bi++) {
-        if (!isdigit(b[bi]) || b[bi] != '.') {
+        if (!isdigit((unsigned char)b[bi]) || b[bi] != '.') {
             return 0;
         }
     }
