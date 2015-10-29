$NetBSD: patch-ntpd-ntpd.c,v 1.1 2015/10/29 11:23:47 christos Exp $

Apply the stupid glibc "warmup" only on linux

--- ntpd/ntpd.c.orig	2015-10-21 12:14:24.000000000 -0400
+++ ntpd/ntpd.c	2015-10-29 07:20:41.000000000 -0400
@@ -32,7 +32,9 @@
 # ifdef HAVE_PTHREAD_H
 #  include <pthread.h>
 # endif
-# define NEED_PTHREAD_WARMUP
+# ifdef __linux__
+#  define NEED_PTHREAD_WARMUP
+# endif
 #endif
 
 #ifdef HAVE_UNISTD_H
