$NetBSD: patch-fstype.c,v 1.3 2014/08/23 20:13:59 wiz Exp $

NetBSD also supports statvfs, adapt checks.
https://github.com/facebook/watchman/issues/49
https://github.com/facebook/watchman/pull/54

--- fstype.c.orig	2014-05-20 21:14:24.000000000 +0000
+++ fstype.c
@@ -53,11 +53,16 @@ w_string_t *w_fstype(const char *path)
   }
 
   return w_string_new(name);
-#elif defined(sun)
+#elif STATVFS_HAS_FSTYPE_AS_STRING
   struct statvfs sfs;
 
   if (statvfs(path, &sfs) == 0) {
+#ifdef HAVE_STRUCT_STATVFS_F_FSTYPENAME
+    return w_string_new(sfs.f_fstypename);
+#endif
+#ifdef HAVE_STRUCT_STATVFS_F_BASETYPE
     return w_string_new(sfs.f_basetype);
+#endif
   }
 #elif HAVE_STATFS
   struct statfs sfs;
