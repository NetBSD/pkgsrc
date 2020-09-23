$NetBSD: patch-src_ln.c,v 1.1 2020/09/23 20:12:50 jperkin Exp $

Backport https://github.com/coreutils/coreutils/commit/3e0dff3925b5e521cae468087950e85b60002d1c

--- src/ln.c.orig	2019-01-05 10:36:22.000000000 +0000
+++ src/ln.c
@@ -603,7 +603,7 @@ main (int argc, char **argv)
     {
       if (n_files == 2 && !target_directory)
         link_errno = atomic_link (file[0], AT_FDCWD, file[1]);
-      if (link_errno < 0 || link_errno == EEXIST || link_errno == ENOTDIR)
+      if (link_errno < 0 || link_errno == EEXIST || link_errno == ENOTDIR || link_errno == EINVAL)
         {
           char const *d
             = target_directory ? target_directory : file[n_files - 1];
