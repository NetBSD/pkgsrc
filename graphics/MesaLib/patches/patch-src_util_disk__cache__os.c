$NetBSD: patch-src_util_disk__cache__os.c,v 1.1 2022/03/13 15:52:50 tnn Exp $

--- src/util/disk_cache_os.c.orig	2021-12-29 21:05:19.000000000 +0000
+++ src/util/disk_cache_os.c
@@ -167,9 +167,13 @@ choose_lru_file_matching(const char *dir
    /* First count the number of files in the directory */
    unsigned total_file_count = 0;
    while ((dir_ent = readdir(dir)) != NULL) {
+#if defined(DT_REG)
       if (dir_ent->d_type == DT_REG) { /* If the entry is a regular file */
          total_file_count++;
       }
+#else
+      total_file_count++;
+#endif
    }
 
    /* Reset to the start of the directory */
