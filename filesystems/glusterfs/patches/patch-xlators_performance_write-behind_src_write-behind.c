$NetBSD: patch-xlators_performance_write-behind_src_write-behind.c,v 1.2 2020/07/27 16:06:08 manu Exp $

NetBSD build fixes
from upstream https://review.gluster.org/24648

--- xlators/performance/write-behind/src/write-behind.c.orig	2020-07-06 03:22:38.006705801 +0200
+++ xlators/performance/write-behind/src/write-behind.c	2020-07-27 17:55:06.263570589 +0200
@@ -2488,9 +2488,9 @@
     wb_inode_t *wb_directory_inode = NULL;
 
     wb_directory_inode = wb_inode_create(this, directory);
 
-    if (!wb_directory_inode || !wb_directory_inode->lock.spinlock)
+    if (!wb_directory_inode)
         return;
 
     LOCK(&wb_directory_inode->lock);
     {
@@ -2508,9 +2508,9 @@
     int readdirps = 0;
 
     wb_directory_inode = wb_inode_ctx_get(this, directory);
 
-    if (!wb_directory_inode || !wb_directory_inode->lock.spinlock)
+    if (!wb_directory_inode)
         return;
 
     LOCK(&wb_directory_inode->lock);
     {
