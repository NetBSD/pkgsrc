$NetBSD: patch-xlators_storage_posix_src_posix-inode-fd-ops.c,v 1.1 2024/08/06 18:51:19 riastradh Exp $

off_t is not unsigned long long; cast it for use with %llx.

--- xlators/storage/posix/src/posix-inode-fd-ops.c.orig	2020-09-16 18:40:32.527503753 +0000
+++ xlators/storage/posix/src/posix-inode-fd-ops.c
@@ -5422,7 +5422,7 @@ posix_fill_readdir(fd_t *fd, DIR *dir, o
                    "seekdir(0x%llx) failed on dir=%p: "
                    "Invalid argument (offset reused from "
                    "another DIR * structure?)",
-                   off, dir);
+                   (unsigned long long)off, dir);
             errno = EINVAL;
             count = -1;
             goto out;
@@ -5495,7 +5495,7 @@ posix_fill_readdir(fd_t *fd, DIR *dir, o
                        "seekdir(0x%llx) failed on dir=%p: "
                        "Invalid argument (offset reused from "
                        "another DIR * structure?)",
-                       in_case, dir);
+                       (unsigned long long)in_case, dir);
                 errno = EINVAL;
                 count = -1;
                 goto out;
