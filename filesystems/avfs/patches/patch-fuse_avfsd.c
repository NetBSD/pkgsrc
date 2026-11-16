$NetBSD: patch-fuse_avfsd.c,v 1.1 2026/11/16 17:37:44 vins Exp $

Make sure PATH_MAX is defined.

--- fuse/avfsd.c.orig	2026-11-16 17:27:45.123393446 +0000
+++ fuse/avfsd.c
@@ -25,6 +25,7 @@
 #include <signal.h>
 #include <pthread.h>
 #include <stddef.h>
+#include <limits.h>
 
 struct fuse *fuse;
 
