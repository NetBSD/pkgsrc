$NetBSD: patch-xlators_features_index_src_index.c,v 1.1 2024/08/06 18:51:19 riastradh Exp $

off_t is not unsigned long long; cast it for use with %llx.

--- xlators/features/index/src/index.c.orig	2023-04-06 09:01:24.955968143 +0000
+++ xlators/features/index/src/index.c
@@ -493,7 +493,7 @@ index_fill_readdir(fd_t *fd, index_fd_ct
                    "seekdir(0x%llx) failed on dir=%p: "
                    "Invalid argument (offset reused from "
                    "another DIR * structure?)",
-                   off, dir);
+                   (unsigned long long)off, dir);
             errno = EINVAL;
             count = -1;
             goto out;
@@ -545,7 +545,7 @@ index_fill_readdir(fd_t *fd, index_fd_ct
                        "seekdir(0x%llx) failed on dir=%p: "
                        "Invalid argument (offset reused from "
                        "another DIR * structure?)",
-                       in_case, dir);
+                       (unsigned long long)in_case, dir);
                 errno = EINVAL;
                 count = -1;
                 goto out;
