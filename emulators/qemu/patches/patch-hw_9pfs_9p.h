$NetBSD: patch-hw_9pfs_9p.h,v 1.1 2025/03/15 20:19:15 riastradh Exp $

Add BSD support for fsdev 9p.

--- hw/9pfs/9p.h.orig	2024-12-10 23:46:36.000000000 +0000
+++ hw/9pfs/9p.h
@@ -238,6 +238,9 @@ static inline void v9fs_readdir_init(P9P
 typedef struct V9fsDirEnt {
     /* mandatory (must not be NULL) information for all readdir requests */
     struct dirent *dent;
+#if !defined(CONFIG_LINUX) && !defined(CONFIG_DARWIN)
+    off_t dirent_off;
+#endif
     /*
      * optional (may be NULL): A full stat of each directory entry is just
      * done if explicitly told to fs driver.
