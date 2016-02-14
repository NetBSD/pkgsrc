$NetBSD: patch-src_bin_evas__cserve2__shm.c,v 1.1 2016/02/14 13:14:06 jperkin Exp $

Use portable PATH_MAX.

--- src/bin/evas_cserve2_shm.c.orig	2012-11-23 16:35:06.000000000 +0000
+++ src/bin/evas_cserve2_shm.c
@@ -56,7 +56,7 @@ cserve2_shm_request(size_t size)
 {
    Shm_Mapping *map;
    Shm_Handle *shm;
-   char shmname[NAME_MAX];
+   char shmname[PATH_MAX];
    size_t map_size;
    int fd;
 
