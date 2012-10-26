$NetBSD: patch-libxfs_xfs__ialloc.c,v 1.1 2012/10/26 20:32:56 joerg Exp $

--- libxfs/xfs_ialloc.c.orig	2012-10-26 15:05:39.000000000 +0000
+++ libxfs/xfs_ialloc.c
@@ -315,7 +315,7 @@ xfs_ialloc_ag_alloc(
 	return 0;
 }
 
-STATIC __inline xfs_agnumber_t
+static xfs_agnumber_t
 xfs_ialloc_next_ag(
 	xfs_mount_t	*mp)
 {
