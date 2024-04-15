$NetBSD: patch-source3_lib_sysquotas__4A.c,v 1.1 2024/04/15 07:16:39 adam Exp $

On Darwin, struct dqblk does not have dqb_curblocks.

--- source3/lib/sysquotas_4A.c.orig	2024-04-14 18:22:12.123682368 +0000
+++ source3/lib/sysquotas_4A.c
@@ -155,7 +155,9 @@ int sys_get_vfs_quota(const char *path,
 	dp->ihardlimit = (uint64_t)D.dqb_ihardlimit;
 	dp->isoftlimit = (uint64_t)D.dqb_isoftlimit;
 	dp->curinodes = (uint64_t)D.dqb_curinodes;
+#if !defined(__APPLE__)
 	dp->curblocks = (uint64_t)D.dqb_curblocks;
+#endif
 
 
 	dp->qflags = qflags;
