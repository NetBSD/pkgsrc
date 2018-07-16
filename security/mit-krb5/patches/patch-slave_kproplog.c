$NetBSD: patch-slave_kproplog.c,v 1.1 2018/07/16 10:26:40 jperkin Exp $

Fix mmap -Werror=incompatible-pointer-types.

--- slave/kproplog.c.orig	2018-05-03 14:34:47.000000000 +0000
+++ slave/kproplog.c
@@ -429,7 +429,7 @@ map_ulog(const char *filename)
         return NULL;
     if (fstat(fd, &st) < 0)
         return NULL;
-    ulog = mmap(0, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
+    ulog = (kdb_hlog_t *)mmap(0, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
     return (ulog == MAP_FAILED) ? NULL : ulog;
 }
 
