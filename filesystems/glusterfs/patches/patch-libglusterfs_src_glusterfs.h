$NetBSD: patch-libglusterfs_src_glusterfs.h,v 1.1 2013/09/08 03:38:52 manu Exp $
--- libglusterfs/src/glusterfs.h.orig	2013-07-18 04:31:33.000000000 +0200
+++ libglusterfs/src/glusterfs.h	2013-07-18 04:32:59.000000000 +0200
@@ -31,8 +31,9 @@
 #include <fcntl.h>
 #include <arpa/inet.h>
 #include <sys/poll.h>
 #include <pthread.h>
+#include <limits.h> /* For PATH_MAX */
 
 #include "list.h"
 #include "logging.h"
 #include "lkowner.h"
