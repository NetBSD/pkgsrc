$NetBSD: patch-ftpfs.c,v 1.1 2022/01/06 03:27:13 pho Exp $

Destroying an uninitialized sem_t results in a segfault on
NetBSD. Just don't do that.

--- ftpfs.c.orig	2022-01-06 03:19:08.654567401 +0000
+++ ftpfs.c
@@ -611,10 +611,6 @@ static void free_ftpfs_file(struct ftpfs
     curl_easy_cleanup(fh->write_conn);
   g_free(fh->full_path);
   g_free(fh->open_path);
-  sem_destroy(&fh->data_avail);
-  sem_destroy(&fh->data_need);
-  sem_destroy(&fh->data_written);
-  sem_destroy(&fh->ready);
   free(fh);
 }
 
