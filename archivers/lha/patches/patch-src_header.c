$NetBSD: patch-src_header.c,v 1.1 2024/09/27 15:13:25 gutteridge Exp $

Fix builds with GCC 14, which treats implicit ints as an error.

--- src/header.c.orig	2021-11-25 09:41:46.000000000 +0000
+++ src/header.c
@@ -68,7 +68,7 @@ calc_sum(p, len)
 }
 
 static void
-_skip_bytes(len)
+_skip_bytes(int len)
 {
     if (len < 0) {
       error("Invalid header: %d", len);
