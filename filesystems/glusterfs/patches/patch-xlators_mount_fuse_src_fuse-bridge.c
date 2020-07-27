$NetBSD: patch-xlators_mount_fuse_src_fuse-bridge.c,v 1.1 2020/07/27 16:06:08 manu Exp $

Make FUSE notification optional at configure time
From upstream https://review.gluster.org/24731

--- xlators/mount/fuse/src/fuse-bridge.c.orig
+++ xlators/mount/fuse/src/fuse-bridge.c
@@ -8,6 +8,8 @@
   cases as published by the Free Software Foundation.
 */
 
+#include <config.h>
+
 #include <sys/wait.h>
 #include "fuse-bridge.h"
 #include <glusterfs/glusterfs.h>
@@ -405,7 +407,7 @@ send_fuse_data(xlator_t *this, fuse_in_header_t *finh, void *data, size_t size)
 static int32_t
 fuse_invalidate_entry(xlator_t *this, uint64_t fuse_ino)
 {
-#if FUSE_KERNEL_MINOR_VERSION >= 11
+#if (FUSE_KERNEL_MINOR_VERSION >= 11 && defined(HAVE_FUSE_NOTIFICATIONS))
     struct fuse_out_header *fouh = NULL;
     struct fuse_notify_inval_entry_out *fnieo = NULL;
     fuse_private_t *priv = NULL;
@@ -496,7 +498,7 @@ fuse_invalidate_entry(xlator_t *this, uint64_t fuse_ino)
 static int32_t
 fuse_invalidate_inode(xlator_t *this, uint64_t fuse_ino)
 {
-#if FUSE_KERNEL_MINOR_VERSION >= 11
+#if (FUSE_KERNEL_MINOR_VERSION >= 11 && defined(HAVE_FUSE_NOTIFICATIONS))
     struct fuse_out_header *fouh = NULL;
     struct fuse_notify_inval_inode_out *fniio = NULL;
     fuse_private_t *priv = NULL;
@@ -4918,7 +4920,7 @@ fuse_setlk(xlator_t *this, fuse_in_header_t *finh, void *msg,
     return;
 }
 
-#if FUSE_KERNEL_MINOR_VERSION >= 11
+#if FUSE_KERNEL_MINOR_VERSION >= 11 && defined(HAVE_FUSE_NOTIFICATIONS)
 static void *
 notify_kernel_loop(void *data)
 {
@@ -5165,6 +5167,7 @@ fuse_init(xlator_t *this, fuse_in_header_t *finh, void *msg,
     priv->timed_response_fuse_thread_started = _gf_true;
 
     /* Used for 'reverse invalidation of inode' */
+#ifdef HAVE_FUSE_NOTIFICATIONS
     if (fini->minor >= 12) {
         ret = gf_thread_create(&messenger, NULL, notify_kernel_loop, this,
                                "fusenoti");
@@ -5176,7 +5179,9 @@ fuse_init(xlator_t *this, fuse_in_header_t *finh, void *msg,
             goto out;
         }
         priv->reverse_fuse_thread_started = _gf_true;
-    } else {
+    } else
+#endif
+    {
         /*
          * FUSE minor < 12 does not implement invalidate notifications.
          * This mechanism is required for fopen-keep-cache to operate
