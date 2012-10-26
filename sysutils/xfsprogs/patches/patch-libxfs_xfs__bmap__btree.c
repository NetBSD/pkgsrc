$NetBSD: patch-libxfs_xfs__bmap__btree.c,v 1.1 2012/10/26 20:32:56 joerg Exp $

--- libxfs/xfs_bmap_btree.c.orig	2012-10-26 15:06:31.000000000 +0000
+++ libxfs/xfs_bmap_btree.c
@@ -1552,7 +1552,7 @@ xfs_bmbt_delete(
  * xfs_bmbt_get_startblock, xfs_bmbt_get_blockcount and xfs_bmbt_get_state.
  */
 
-STATIC __inline__ void
+static void
 __xfs_bmbt_get_all(
 		__uint64_t l0,
 		__uint64_t l1,
