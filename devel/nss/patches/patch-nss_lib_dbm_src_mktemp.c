$NetBSD: patch-nss_lib_dbm_src_mktemp.c,v 1.1 2022/04/07 19:08:40 riastradh Exp $

Fix ctype(3) abuse: https://bugzilla.mozilla.org/show_bug.cgi?id=1246768

--- nss/lib/dbm/src/mktemp.c.orig	2022-03-03 10:18:53.000000000 +0000
+++ nss/lib/dbm/src/mktemp.c
@@ -137,7 +137,7 @@ _gettemp(char *path, register int *doope
             if (*trv == 'z')
                 *trv++ = 'a';
             else {
-                if (isdigit(*trv))
+                if (isdigit((unsigned char)*trv))
                     *trv = 'a';
                 else
                     ++*trv;
