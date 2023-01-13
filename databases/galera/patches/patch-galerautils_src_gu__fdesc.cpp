$NetBSD: patch-galerautils_src_gu__fdesc.cpp,v 1.1 2023/01/13 16:08:03 wiz Exp $

NetBSD man page suggests ftruncate() before posix_fallocate().
Also recognize NetBSD's errno if unsupported.
https://github.com/codership/galera/pull/632

--- galerautils/src/gu_fdesc.cpp.orig	2022-11-02 06:09:14.000000000 +0000
+++ galerautils/src/gu_fdesc.cpp
@@ -235,13 +235,16 @@ namespace gu
 #if defined(__APPLE__)
         if (-1 == fcntl (fd_, F_SETSIZE, size_) && -1 == ftruncate (fd_, size_))
         {
+#elif defined(__NetBSD__)
+        if (-1 == ftruncate (fd_, size_) || 0 != posix_fallocate (fd_, start, diff))
+        {
 #else
         int const ret = posix_fallocate (fd_, start, diff);
         if (0 != ret)
         {
             errno = ret;
 #endif
-            if ((EINVAL == errno || ENOSYS == errno) && start >= 0 && diff > 0)
+            if ((EINVAL == errno || ENOSYS == errno || EOPNOTSUPP == errno) && start >= 0 && diff > 0)
             {
                 // FS does not support the operation, try physical write
                 write_file (start);
