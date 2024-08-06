$NetBSD: patch-contrib_umountd_umountd.c,v 1.1 2024/08/06 18:51:19 riastradh Exp $

Fix format strings.

--- contrib/umountd/umountd.c.orig	2020-09-16 18:40:32.181503544 +0000
+++ contrib/umountd/umountd.c
@@ -163,7 +163,7 @@ umountd_async (char *path, dev_t dev, in
                 ret = sys_lstat (path, &stbuf);
                 if (ret != 0) {
                         gf_log ("umountd", GF_LOG_WARNING,
-                                      "Cannot stat device from %s",
+                                      "Cannot stat device from %s: %s",
                                 path, strerror (errno));
                         break;
                 }
@@ -172,7 +172,8 @@ umountd_async (char *path, dev_t dev, in
                         if (unmount_ret != 0)
                                 gf_log ("umountd", GF_LOG_INFO,
                                         "device mismatch "
-                                        "(expect %lld, found %lld), "
+                                        "(expect %" GF_PRI_DEV
+                                        ", found %" GF_PRI_DEV "), "
                                         "someone else unmounted %s",
                                         dev, stbuf.st_dev, path);
                         ret = 0;
