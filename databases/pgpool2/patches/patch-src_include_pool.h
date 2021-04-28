$NetBSD: patch-src_include_pool.h,v 1.2 2021/04/28 09:18:55 wiz Exp $

Default pid file location.

--- src/include/pool.h.orig	2021-04-24 00:34:31.131959515 +0300
+++ src/include/pool.h	2021-04-24 00:35:57.462247644 +0300
@@ -78,7 +78,7 @@
 #define DEFAULT_WD_IPC_SOCKET_DIR "/tmp"
 
 /* pid file name */
-#define DEFAULT_PID_FILE_NAME "/var/run/pgpool/pgpool.pid"
+#define DEFAULT_PID_FILE_NAME "@PGPOOL_PIDDIR@/pgpool.pid"
 
 /* status file name */
 #define STATUS_FILE_NAME "pgpool_status"
