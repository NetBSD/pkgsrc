$NetBSD: patch-src_cluster.c,v 1.1 2015/04/13 11:33:35 fhajny Exp $

Add fcntl support on SunOS.

--- src/cluster.c.orig	2015-04-01 14:01:44.000000000 +0000
+++ src/cluster.c
@@ -369,8 +369,19 @@ int clusterLockConfig(char *filename) {
         return REDIS_ERR;
     }
 
+#ifdef __sun
+    struct flock lock;
+    lock.l_start = 0;
+    lock.l_len = 0;
+    lock.l_type = F_WRLCK;
+    lock.l_whence = SEEK_SET;
+
+    if (fcntl(fd,F_SETLK,&lock) == -1) {
+        if (errno == EAGAIN) {
+#else
     if (flock(fd,LOCK_EX|LOCK_NB) == -1) {
         if (errno == EWOULDBLOCK) {
+#endif
             redisLog(REDIS_WARNING,
                  "Sorry, the cluster configuration file %s is already used "
                  "by a different Redis Cluster node. Please make sure that "
