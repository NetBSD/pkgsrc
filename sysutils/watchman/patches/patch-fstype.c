$NetBSD: patch-fstype.c,v 1.1 2014/08/09 22:59:30 wiz Exp $

NetBSD also supports statvfs, adapt checks.

--- fstype.c.orig	2014-05-20 21:14:24.000000000 +0000
+++ fstype.c
@@ -53,11 +53,15 @@ w_string_t *w_fstype(const char *path)
   }
 
   return w_string_new(name);
-#elif defined(sun)
+#elif HAVE_SYS_STATVFS_H
   struct statvfs sfs;
 
   if (statvfs(path, &sfs) == 0) {
+#ifdef __NetBSD__
+    return w_string_new(sfs.f_fstypename);
+#else
     return w_string_new(sfs.f_basetype);
+#endif
   }
 #elif HAVE_STATFS
   struct statfs sfs;
