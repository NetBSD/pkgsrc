$NetBSD: patch-src_wutil.cpp,v 1.4 2020/02/18 22:00:49 maya Exp $

fstatfs appears to be linux-specific, let's not try it on non-linux

--- src/wutil.cpp.orig	2020-02-12 14:04:07.000000000 +0000
+++ src/wutil.cpp
@@ -320,7 +320,7 @@ int fd_check_is_remote(int fd) {
     struct statvfs buf {};
     if (fstatvfs(fd, &buf) < 0) return -1;
     return (buf.f_flag & ST_LOCAL) ? 0 : 1;
-#elif defined(MNT_LOCAL)
+#elif defined(MNT_LOCAL) && defined(__linux__)
     struct statfs buf {};
     if (fstatfs(fd, &buf) < 0) return -1;
     return (buf.f_flags & MNT_LOCAL) ? 0 : 1;
