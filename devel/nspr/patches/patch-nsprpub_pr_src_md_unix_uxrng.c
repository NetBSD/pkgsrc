$NetBSD: patch-nsprpub_pr_src_md_unix_uxrng.c,v 1.4 2019/12/03 14:28:26 ryoon Exp $

--- nspr/pr/src/md/unix/uxrng.c.orig	2019-10-15 14:21:38.000000000 +0000
+++ nspr/pr/src/md/unix/uxrng.c
@@ -64,7 +64,7 @@ GetHighResClock(void *buf, size_t maxbyt
 
 #elif (defined(LINUX) || defined(FREEBSD) || defined(__FreeBSD_kernel__) \
     || defined(NETBSD) || defined(__NetBSD_kernel__) || defined(OPENBSD) \
-    || defined(__GNU__))
+    || defined(__GNU__)) || defined(__DragonFly__)
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
