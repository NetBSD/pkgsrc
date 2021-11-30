$NetBSD: patch-src_bindfs.c,v 1.1 2021/11/30 12:34:24 pho Exp $

Fix compatibility with FUSE 2.6: ioctl() is not supported.

--- src/bindfs.c.orig	2021-11-30 11:04:33.969893934 +0000
+++ src/bindfs.c
@@ -1721,8 +1721,8 @@ static struct fuse_operations bindfs_ope
 #if defined(HAVE_FUSE_29) || defined(HAVE_FUSE_3)
     .lock       = bindfs_lock,
     .flock      = bindfs_flock,
-#endif
     .ioctl      = bindfs_ioctl,
+#endif
     .statfs     = bindfs_statfs,
     .release    = bindfs_release,
     .fsync      = bindfs_fsync,
@@ -2843,10 +2843,18 @@ int main(int argc, char *argv[])
     }
 #endif
 
+#if defined(HAVE_FUSE_29) || defined(HAVE_FUSE_3)
     /* Remove the ioctl implementation unless the user has enabled it */
     if (!settings.enable_ioctl) {
         bindfs_oper.ioctl = NULL;
     }
+#else
+    if (settings.enable_ioctl) {
+        fprintf(stderr, "To use --enable-ioctl, bindfs must be "
+                        "compiled with FUSE 2.9.0 or newer.\n");
+        return 1;
+    }
+#endif
 
     /* Remove/Ignore some special -o options */
     args = filter_special_opts(&args);
