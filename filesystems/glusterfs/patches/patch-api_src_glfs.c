$NetBSD: patch-api_src_glfs.c,v 1.1 2024/08/06 18:54:01 riastradh Exp $

Avoid ctype(3) abuse.

--- api/src/glfs.c.orig	2023-04-06 09:01:24.660967197 +0000
+++ api/src/glfs.c
@@ -861,7 +861,7 @@ pub_glfs_new(const char *volname)
     }
 
     for (i = 0; i < strlen(volname); i++) {
-        if (!isalnum(volname[i]) && (volname[i] != '_') &&
+        if (!isalnum((unsigned char)volname[i]) && (volname[i] != '_') &&
             (volname[i] != '-')) {
             errno = EINVAL;
             return NULL;
