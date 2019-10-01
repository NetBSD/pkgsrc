$NetBSD: patch-unix_uxucs.c,v 1.3 2019/10/01 15:22:41 ryoon Exp $

--- unix/uxucs.c.orig	2019-09-22 09:14:52.000000000 +0000
+++ unix/uxucs.c
@@ -68,7 +68,7 @@ int wc_to_mb(int codepage, int flags, co
         memset(&state, 0, sizeof state);
 
         while (wclen > 0) {
-            int i = wcrtomb(output, wcstr[0], &state);
+            size_t i = wcrtomb(output, wcstr[0], &state);
             if (i == (size_t)-1 || i > n - mblen)
                 break;
             memcpy(mbstr+n, output, i);
