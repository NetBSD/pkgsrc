$NetBSD: patch-monitor__kqueue.c,v 1.1 2018/06/02 12:53:10 jmcneill Exp $

--- monitor_kqueue.c.orig	2018-05-04 23:11:25.000000000 +0000
+++ monitor_kqueue.c
@@ -181,14 +181,35 @@ dir_vnode_process(struct event *ev, u_in
 					break;
 				}
 			if (!found_flag ) {
+				struct timespec ts;
 				struct stat st;
+				bool error_flag = false;
 
-				if (stat(tmp_path, &st) != 0) {
-					DPRINTF(E_ERROR, L_INOTIFY,
-					    "stat(%s): %s\n", tmp_path,
-					    strerror(errno));
+				for (;;) {
+					if (stat(tmp_path, &st) != 0) {
+						DPRINTF(E_ERROR, L_INOTIFY,
+						    "stat(%s): %s\n", tmp_path,
+						    strerror(errno));
+						error_flag = true;
+						break;
+					}
+					if (clock_gettime(CLOCK_REALTIME, &ts) != 0) {
+						DPRINTF(E_ERROR, L_INOTIFY,
+						    "clock_gettime(CLOCK_REALTIME): %s\n",
+						    strerror(errno));
+						break;
+					}
+					ts.tv_sec -= 5;
+					if (timespeccmp(&st.st_mtimespec, &ts, <)) {
+						break;
+					}
+					sleep(1);
+				}
+
+				if (error_flag) {
 					continue;
 				}
+						
 				esc_name = strdup(entry->d_name);
 				if (esc_name == NULL) {
 					DPRINTF(E_ERROR, L_INOTIFY,
