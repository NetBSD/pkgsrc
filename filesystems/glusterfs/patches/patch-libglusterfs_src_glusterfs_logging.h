$NetBSD: patch-libglusterfs_src_glusterfs_logging.h,v 1.1 2024/08/06 18:51:19 riastradh Exp $

time_t is always int64_t on NetBSD(>=6), not unsigned long.
suseconds_t is int on NetBSD, not long.

--- libglusterfs/src/glusterfs/logging.h.orig	2023-04-06 09:01:24.752967492 +0000
+++ libglusterfs/src/glusterfs/logging.h
@@ -32,8 +32,13 @@
 #define GF_PRI_DEV PRIu64
 #define GF_PRI_INODE PRIu64
 #define GF_PRI_NLINK PRIu32
+#ifdef __NetBSD__
+#define GF_PRI_SECOND PRId64
+#define GF_PRI_SUSECONDS "06d"
+#else
 #define GF_PRI_SECOND "lu"
 #define GF_PRI_SUSECONDS "06ld"
+#endif
 #define GF_PRI_SNSECONDS "09ld"
 #define GF_PRI_USEC "ld"
 #endif
