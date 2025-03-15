$NetBSD: patch-hw_9pfs_codir.c,v 1.1 2025/03/15 20:19:15 riastradh Exp $

Add BSD support for fsdev 9p.

--- hw/9pfs/codir.c.orig	2024-12-10 23:46:36.000000000 +0000
+++ hw/9pfs/codir.c
@@ -122,6 +122,13 @@ do_readdir_many(V9fsPDU *pdu, V9fsFidSta
         if (err || !dent) {
             break;
         }
+#if !defined(CONFIG_LINUX) && !defined(CONFIG_DARWIN)
+        const off_t dirent_off = s->ops->telldir(&s->ctx, &fidp->fs);
+        if (dirent_off < 0) {
+            err = dirent_off;
+            break;
+        }
+#endif
 
         /*
          * stop this loop as soon as it would exceed the allowed maximum
@@ -145,6 +152,9 @@ do_readdir_many(V9fsPDU *pdu, V9fsFidSta
             e = e->next = g_new0(V9fsDirEnt, 1);
         }
         e->dent = qemu_dirent_dup(dent);
+#if !defined(CONFIG_LINUX) && !defined(CONFIG_DARWIN)
+        e->dirent_off = dirent_off;
+#endif
 
         /* perform a full stat() for directory entry if requested by caller */
         if (dostat) {
@@ -167,7 +177,11 @@ do_readdir_many(V9fsPDU *pdu, V9fsFidSta
         }
 
         size += len;
+#if !defined(CONFIG_LINUX) && !defined(CONFIG_DARWIN)
+        saved_dir_pos = dirent_off;
+#else
         saved_dir_pos = qemu_dirent_off(dent);
+#endif
     }
 
     /* restore (last) saved position */
