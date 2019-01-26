$NetBSD: patch-src_lib_notify.c,v 1.1.1.1 2019/01/26 00:57:56 alnsn Exp $

Add include for struct timespec.

--- src/lib/notify.c.orig	2017-10-13 23:52:42.000000000 +0000
+++ src/lib/notify.c
@@ -34,6 +34,7 @@
 #include <errno.h>	/* ENAMETOOLONG EINTR EAGAIN EMFILE EISDIR ENOTDIR */
 
 #include <sys/queue.h>	/* LIST_* */
+#include <sys/time.h>
 #include <unistd.h>	/* close(2) */
 #include <fcntl.h>	/* O_CLOEXEC O_DIRECTORY ... open(2) openat(2) fcntl(2) */
 #include <dirent.h>	/* DIR fdopendir(3) opendir(3) readdir_r(3) closedir(3) */
