$NetBSD: patch-kprop_kproplog.c,v 1.2 2024/01/05 23:46:29 adam Exp $

Fix mmap -Werror=incompatible-pointer-types.

--- kprop/kproplog.c.orig	2023-08-14 16:16:43.000000000 +0000
+++ kprop/kproplog.c
@@ -415,7 +415,7 @@ map_ulog(const char *filename, int *fd_o
         close(fd);
         return NULL;
     }
-    ulog = mmap(0, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
+    ulog = (kdb_hlog_t *)mmap(0, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
     if (ulog == MAP_FAILED) {
         close(fd);
         return NULL;
