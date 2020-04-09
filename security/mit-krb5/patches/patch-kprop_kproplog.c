$NetBSD: patch-kprop_kproplog.c,v 1.1 2020/04/09 10:57:49 adam Exp $

Fix mmap -Werror=incompatible-pointer-types.

--- kprop/kproplog.c.orig	2020-04-09 08:50:26.000000000 +0000
+++ kprop/kproplog.c
@@ -412,7 +412,7 @@ map_ulog(const char *filename)
         return NULL;
     if (fstat(fd, &st) < 0)
         return NULL;
-    ulog = mmap(0, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
+    ulog = (kdb_hlog_t *)mmap(0, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
     return (ulog == MAP_FAILED) ? NULL : ulog;
 }
 
