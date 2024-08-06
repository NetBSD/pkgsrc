$NetBSD: patch-xlators_storage_posix_src_posix-inode-fd-ops.c,v 1.1 2024/08/06 18:51:19 riastradh Exp $

off_t is not unsigned long long; cast it for use with %llx.

--- xlators/storage/posix/src/posix-inode-fd-ops.c.orig	2023-04-06 09:01:25.088968570 +0000
+++ xlators/storage/posix/src/posix-inode-fd-ops.c
@@ -5583,7 +5583,7 @@ posix_fill_readdir(fd_t *fd, struct posi
                    "seekdir(0x%llx) failed on dir=%p: "
                    "Invalid argument (offset reused from "
                    "another DIR * structure?)",
-                   off, pfd->dir);
+                   (unsigned long long)off, pfd->dir);
             errno = EINVAL;
             count = -1;
             goto out;
@@ -5659,7 +5659,7 @@ posix_fill_readdir(fd_t *fd, struct posi
                        "seekdir(0x%llx) failed on dir=%p: "
                        "Invalid argument (offset reused from "
                        "another DIR * structure?)",
-                       in_case, pfd->dir);
+                       (unsigned long long)in_case, pfd->dir);
                 errno = EINVAL;
                 count = -1;
                 goto out;
