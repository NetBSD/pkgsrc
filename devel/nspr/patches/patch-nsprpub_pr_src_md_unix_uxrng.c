$NetBSD: patch-nsprpub_pr_src_md_unix_uxrng.c,v 1.2 2012/06/07 13:48:21 ryoon Exp $

--- nsprpub/pr/src/md/unix/uxrng.c.orig	2012-05-18 21:55:29.000000000 +0000
+++ nsprpub/pr/src/md/unix/uxrng.c
@@ -94,7 +94,7 @@ GetHighResClock(void *buf, size_t maxbyt
 
 #elif (defined(LINUX) || defined(FREEBSD) || defined(__FreeBSD_kernel__) \
     || defined(NETBSD) || defined(__NetBSD_kernel__) || defined(OPENBSD) \
-    || defined(SYMBIAN) || defined(__GNU__))
+    || defined(SYMBIAN) || defined(__GNU__)) || defined(__DragonFly__)
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
