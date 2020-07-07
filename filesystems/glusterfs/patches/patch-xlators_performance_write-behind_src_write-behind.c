$NetBSD: patch-xlators_performance_write-behind_src_write-behind.c,v 1.1 2020/07/07 01:01:27 manu Exp $

--- xlators/performance/write-behind/src/write-behind.c.orig	2020-06-28 02:50:52.965398208 +0200
+++ xlators/performance/write-behind/src/write-behind.c	2020-06-28 02:58:49.641108451 +0200
@@ -2488,9 +2488,13 @@
     wb_inode_t *wb_directory_inode = NULL;
 
     wb_directory_inode = wb_inode_create(this, directory);
 
-    if (!wb_directory_inode || !wb_directory_inode->lock.spinlock)
+    if (!wb_directory_inode 
+#ifndef __NetBSD__
+        || !wb_directory_inode->lock.spinlock
+#endif
+    )
         return;
 
     LOCK(&wb_directory_inode->lock);
     {
@@ -2508,9 +2512,13 @@
     int readdirps = 0;
 
     wb_directory_inode = wb_inode_ctx_get(this, directory);
 
-    if (!wb_directory_inode || !wb_directory_inode->lock.spinlock)
+    if (!wb_directory_inode
+#ifndef __NetBSD__
+        || !wb_directory_inode->lock.spinlock
+#endif
+    )
         return;
 
     LOCK(&wb_directory_inode->lock);
     {
