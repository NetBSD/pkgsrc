$NetBSD: patch-src_util_disk__cache.c,v 1.1 2018/10/16 15:21:20 jperkin Exp $

Use fcntl() on SunOS.

--- src/util/disk_cache.c.orig	2018-09-07 21:18:07.000000000 +0000
+++ src/util/disk_cache.c
@@ -857,6 +857,9 @@ cache_put(void *job, int thread_index)
    unsigned i = 0;
    char *filename = NULL, *filename_tmp = NULL;
    struct disk_cache_put_job *dc_job = (struct disk_cache_put_job *) job;
+#ifdef __sun
+   struct flock lock = {0};
+#endif
 
    filename = get_cache_file(dc_job->cache, dc_job->key);
    if (filename == NULL)
@@ -895,7 +898,12 @@ cache_put(void *job, int thread_index)
     * open with the flock held. So just let that file be responsible
     * for writing the file.
     */
+#ifdef __sun
+   lock.l_type = F_WRLCK;
+   err = fcntl(fd, F_SETLK, &lock);
+#else
    err = flock(fd, LOCK_EX | LOCK_NB);
+#endif
    if (err == -1)
       goto done;
 
