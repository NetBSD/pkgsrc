$NetBSD: patch-src_header.c,v 1.2 2024/10/02 22:17:11 gutteridge Exp $

Fix builds with GCC 14, which treats implicit ints as an error.
https://github.com/jca02266/lha/commit/a5c5d438537125bfe936ea523e7bc981a50364a2

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
