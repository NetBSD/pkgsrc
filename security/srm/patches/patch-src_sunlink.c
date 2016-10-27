$NetBSD: patch-src_sunlink.c,v 1.1 2016/10/27 19:49:44 kamil Exp $

Add NetBSD support.

--- src/sunlink.c.orig	2015-02-26 16:12:02.000000000 +0000
+++ src/sunlink.c
@@ -105,7 +105,7 @@ static volatile int SIGINT_received = 0;
 #if defined(__linux__) && !defined(__USE_GNU)
 typedef __sighandler_t sighandler_t;
 #endif
-#if defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 typedef sig_t sighandler_t;
 #endif
 
@@ -837,8 +837,13 @@ next_ads:
 
 #if defined(HAVE_SYS_VFS_H) || (defined(HAVE_SYS_PARAM_H) && defined(HAVE_SYS_MOUNT_H))
   {
+#if defined(__NetBSD__)
+    struct statvfs fs_stats;
+    if (fstatvfs(srm.fd, &fs_stats) < 0 && errno != ENOSYS)
+#else
     struct statfs fs_stats;
     if (fstatfs(srm.fd, &fs_stats) < 0 && errno != ENOSYS)
+#endif
       {
 	int e=errno;
 	close(srm.fd);
@@ -848,7 +853,7 @@ next_ads:
 
 #if defined(__linux__)
     srm.buffer_size = fs_stats.f_bsize;
-#elif defined(__FreeBSD__) || defined(__APPLE__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__APPLE__)
     srm.buffer_size = fs_stats.f_iosize;
 #else
 #error Please define your platform.
@@ -907,6 +912,7 @@ next_ads:
    and catch only platforms supporting NOUNLINK here.
 
    OpenBSD - doesn't support nounlink (As of 3.1)
+   NetBSD  - doesn't support nounlink (as of 7.99.41)
    FreeBSD - supports nounlink (from 4.4 on?)
    Tru64   - unknown
    MacOS X - doesn't support NOUNLINK (as of 10.3.5)
