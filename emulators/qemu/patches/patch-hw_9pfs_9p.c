$NetBSD: patch-hw_9pfs_9p.c,v 1.2 2026/01/05 10:11:38 adam Exp $

Add BSD support for fsdev 9p.

--- hw/9pfs/9p.c.orig	2025-12-23 19:48:56.000000000 +0000
+++ hw/9pfs/9p.c
@@ -136,7 +136,7 @@ static int dotl_to_open_flags(int flags)
         { P9_DOTL_NONBLOCK, O_NONBLOCK } ,
         { P9_DOTL_DSYNC, O_DSYNC },
         { P9_DOTL_FASYNC, FASYNC },
-#if !defined(CONFIG_DARWIN) && !defined(CONFIG_FREEBSD)
+#if !defined(CONFIG_DARWIN) && !defined(CONFIG_FREEBSD) && defined(O_NOATIME)
         { P9_DOTL_NOATIME, O_NOATIME },
 #endif
 #ifndef CONFIG_DARWIN
@@ -2365,6 +2365,13 @@ static int coroutine_fn v9fs_do_readdir_
         if (err || !dent) {
             break;
         }
+#if !defined(CONFIG_LINUX) && !defined(CONFIG_DARWIN)
+        const off_t next_dir_pos = v9fs_co_telldir(pdu, fidp);
+        if (next_dir_pos < 0) {
+            err = next_dir_pos;
+            break;
+        }
+#endif
         err = v9fs_co_name_to_path(pdu, &fidp->path, dent->d_name, &path);
         if (err < 0) {
             break;
@@ -2401,7 +2408,11 @@ static int coroutine_fn v9fs_do_readdir_
         count += len;
         v9fs_stat_free(&v9stat);
         v9fs_path_free(&path);
+#if !defined(CONFIG_LINUX) && !defined(CONFIG_DARWIN)
+        saved_dir_pos = next_dir_pos;
+#else
         saved_dir_pos = qemu_dirent_off(dent);
+#endif
     }
 
     v9fs_readdir_unlock(&fidp->fs.dir);
@@ -2602,7 +2613,11 @@ static int coroutine_fn v9fs_do_readdir(
             qid.version = 0;
         }
 
+#if !defined(CONFIG_LINUX) && !defined(CONFIG_DARWIN)
+        off = e->dirent_off;
+#else
         off = qemu_dirent_off(dent);
+#endif
         v9fs_string_init(&name);
         v9fs_string_sprintf(&name, "%s", dent->d_name);
 
@@ -3647,7 +3662,11 @@ static int v9fs_fill_statfs(V9fsState *s
     if (!bsize_factor) {
         bsize_factor = 1;
     }
+#ifdef __NetBSD__
+    f_type  = 0;                /* XXX struct statvfs::f_type? (fstypename?) */
+#else
     f_type  = stbuf->f_type;
+#endif
     f_bsize = stbuf->f_bsize;
     f_bsize *= bsize_factor;
     /*
@@ -3664,10 +3683,14 @@ static int v9fs_fill_statfs(V9fsState *s
     fsid_val = (unsigned int)stbuf->f_fsid.val[0] |
                (unsigned long long)stbuf->f_fsid.val[1] << 32;
     f_namelen = NAME_MAX;
-#else
+#elif defined CONFIG_LINUX
     fsid_val = (unsigned int) stbuf->f_fsid.__val[0] |
                (unsigned long long)stbuf->f_fsid.__val[1] << 32;
     f_namelen = stbuf->f_namelen;
+#elif defined __NetBSD__
+    fsid_val = (unsigned int) stbuf->f_fsidx.__fsid_val[0] |
+               (unsigned long long)stbuf->f_fsidx.__fsid_val[1] << 32;
+    f_namelen = NAME_MAX;
 #endif
 
     return pdu_marshal(pdu, offset, "ddqqqqqqd",
@@ -4038,7 +4061,7 @@ out_nofid:
     v9fs_string_free(&name);
 }
 
-#if defined(CONFIG_LINUX)
+#if defined(CONFIG_LINUX) || defined(__NetBSD__)
 /* Currently, only Linux has XATTR_SIZE_MAX */
 #define P9_XATTR_SIZE_MAX XATTR_SIZE_MAX
 #elif defined(CONFIG_DARWIN)
