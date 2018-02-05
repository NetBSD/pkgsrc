$NetBSD: patch-src_sarray1.c,v 1.1 2018/02/05 10:53:36 jperkin Exp $

Use stat(2) until they have proper autoconf tests for fstatat(2).

--- src/sarray1.c.orig	2018-01-31 15:57:06.000000000 +0000
+++ src/sarray1.c
@@ -1873,7 +1873,7 @@ struct stat     st;
     while ((pdirentry = readdir(pdir))) {
 
         /* It's nice to ignore directories.  */
-      if ((0 == fstatat(dfd, pdirentry->d_name, &st, 0))
+      if ((0 == stat(pdirentry->d_name, &st))
           && S_ISDIR(st.st_mode)) {
             continue;
       }
