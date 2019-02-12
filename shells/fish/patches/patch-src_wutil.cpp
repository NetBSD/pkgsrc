$NetBSD: patch-src_wutil.cpp,v 1.3 2019/02/12 16:49:31 maya Exp $

fstatfs appears to be linux-specific, let's not try it on non-linux

--- src/wutil.cpp.orig	2018-12-28 13:01:03.000000000 +0000
+++ src/wutil.cpp
@@ -311,10 +311,6 @@ int fd_check_is_remote(int fd) {
             // Other FSes are assumed local.
             return 0;
     }
-#elif defined(MNT_LOCAL)
-    struct statfs buf {};
-    if (fstatfs(fd, &buf) < 0) return -1;
-    return (buf.f_flags & MNT_LOCAL) ? 0 : 1;
 #else
     return -1;
 #endif
