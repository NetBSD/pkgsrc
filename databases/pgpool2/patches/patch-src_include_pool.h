$NetBSD: patch-src_include_pool.h,v 1.1 2016/03/11 21:30:55 fhajny Exp $

Default pid file location.

--- src/include/pool.h.orig	2016-02-20 00:28:07.000000000 +0200
+++ src/include/pool.h		2016-02-20 00:29:09.000000000 +0200
@@ -81,7 +81,7 @@
 #define DEFAULT_WD_IPC_SOCKET_DIR "/tmp"
 
 /* pid file name */
-#define DEFAULT_PID_FILE_NAME "/var/run/pgpool/pgpool.pid"
+#define DEFAULT_PID_FILE_NAME "@PGPOOL_PIDDIR@/pgpool.pid"
 
 /* status file name */
 #define STATUS_FILE_NAME "pgpool_status"
