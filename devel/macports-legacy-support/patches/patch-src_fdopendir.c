$NetBSD: patch-src_fdopendir.c,v 1.1 2023/11/15 15:23:13 nia Exp $

Fix 10.4 support.
https://github.com/macports/macports-legacy-support/pull/69

--- src/fdopendir.c.orig	2023-09-15 08:59:52.000000000 +0000
+++ src/fdopendir.c
@@ -29,6 +29,13 @@
 #include <sys/errno.h>
 
 #undef DIR
+#undef opendir
+#undef closedir
+#undef readdir
+#undef readdir_r
+#undef rewinddir
+#undef seekdir
+#undef telldir
 
 
 /*
@@ -52,7 +59,7 @@ __MPLS_DIR *fdopendir(int dirfd) {
 
     /* Open the supplied directory safely */
 
-    DIR *dir = _ATCALL(dirfd, ".", NULL, __mpls_libc_opendir("."));
+    DIR *dir = _ATCALL(dirfd, ".", NULL, opendir("."));
     if (!dir)
         return 0;
 
@@ -60,7 +67,7 @@ __MPLS_DIR *fdopendir(int dirfd) {
 
     __MPLS_DIR *mplsdir = malloc(sizeof(*mplsdir));
     if (!mplsdir) {
-        (void)__mpls_libc_closedir(dir);
+        (void)closedir(dir);
         errno = ENOMEM;
         return 0;
     }
@@ -80,13 +87,13 @@ __MPLS_DIR *fdopendir(int dirfd) {
 
 __MPLS_DIR *__mpls_opendir(const char *name) {
 
-    DIR *dir = __mpls_libc_opendir(name);
+    DIR *dir = opendir(name);
     if (!dir)
         return 0;
 
     __MPLS_DIR *mplsdir = malloc(sizeof(*mplsdir));
     if (!mplsdir) {
-        (void)__mpls_libc_closedir(dir);
+        (void)closedir(dir);
         errno = ENOMEM;
         return 0;
     }
@@ -112,7 +119,7 @@ int __mpls_closedir(__MPLS_DIR *mplsdir)
         return -1;
     }
 
-    int rc = __mpls_libc_closedir(mplsdir->__mpls_dir);
+    int rc = closedir(mplsdir->__mpls_dir);
 
     if (mplsdir->__mpls_dirfd != -1)
         PROTECT_ERRNO(close(mplsdir->__mpls_dirfd));
@@ -127,7 +134,7 @@ int __mpls_closedir(__MPLS_DIR *mplsdir)
  */
 
 struct dirent *__mpls_readdir(__MPLS_DIR *mplsdir) {
-    return __mpls_libc_readdir(mplsdir->__mpls_dir);
+    return readdir(mplsdir->__mpls_dir);
 }
 
 /*
@@ -135,7 +142,7 @@ struct dirent *__mpls_readdir(__MPLS_DIR
  */
 
 int __mpls_readdir_r(__MPLS_DIR *mplsdir, struct dirent *entry, struct dirent **result) {
-    return __mpls_libc_readdir_r(mplsdir->__mpls_dir, entry, result);
+    return readdir_r(mplsdir->__mpls_dir, entry, result);
 }
 
 /*
@@ -143,7 +150,7 @@ int __mpls_readdir_r(__MPLS_DIR *mplsdir
  */
 
 void __mpls_rewinddir(__MPLS_DIR *mplsdir) {
-    __mpls_libc_rewinddir(mplsdir->__mpls_dir);
+    rewinddir(mplsdir->__mpls_dir);
 }
 
 /*
@@ -151,7 +158,7 @@ void __mpls_rewinddir(__MPLS_DIR *mplsdi
  */
 
 void __mpls_seekdir(__MPLS_DIR *mplsdir, long loc) {
-    __mpls_libc_seekdir(mplsdir->__mpls_dir, loc);
+    seekdir(mplsdir->__mpls_dir, loc);
 }
 
 /*
@@ -159,7 +166,7 @@ void __mpls_seekdir(__MPLS_DIR *mplsdir,
  */
 
 long __mpls_telldir(__MPLS_DIR *mplsdir) {
-    return __mpls_libc_telldir(mplsdir->__mpls_dir);
+    return telldir(mplsdir->__mpls_dir);
 }
 
 /*
