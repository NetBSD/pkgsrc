$NetBSD: patch-api_src_glfs.c,v 1.2 2024/08/06 21:10:48 riastradh Exp $

Avoid ctype(3) abuse.
https://github.com/gluster/glusterfs/issues/4397

--- api/src/glfs.c.orig	2020-09-16 18:40:32.159503531 +0000
+++ api/src/glfs.c
@@ -827,7 +827,7 @@ pub_glfs_new(const char *volname)
     }
 
     for (i = 0; i < strlen(volname); i++) {
-        if (!isalnum(volname[i]) && (volname[i] != '_') &&
+        if (!isalnum((unsigned char)volname[i]) && (volname[i] != '_') &&
             (volname[i] != '-')) {
             errno = EINVAL;
             return NULL;
