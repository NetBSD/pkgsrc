$NetBSD: patch-utf8proc.c,v 1.1 2025/10/05 10:47:21 js Exp $

--- utf8proc.c.orig	2024-12-31 20:17:14.000000000 +0000
+++ utf8proc.c
@@ -689,7 +689,8 @@ UTF8PROC_DLLEXPORT utf8proc_ssize_t utf8
           utf8proc_int32_t max_second = utf8proc_combinations_second[idx + len - 1];
           if (current_char <= max_second) {
             // TODO: binary search? arithmetic search?
-            for (int off = 0; off < len; ++off) {
+            int off;
+            for (off = 0; off < len; ++off) {
               utf8proc_int32_t second = utf8proc_combinations_second[idx + off];
               if (current_char < second) {
                 /* not found */
