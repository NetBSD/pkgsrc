$NetBSD: patch-fscd_fscd.c,v 1.1 2013/09/10 14:43:23 joerg Exp $

--- fscd/fscd.c.orig	2012-11-12 00:12:33.000000000 +0000
+++ fscd/fscd.c
@@ -1067,6 +1067,10 @@ handle_task(struct fscd_cfg *config, cha
 		print_status(config, sock_fd);
 		pthread_mutex_unlock(&config->service_mtx);
 		return 0;
+	} else {
+		printlog(LOG_ERR, "received invalid message from client.");
+		pthread_mutex_unlock(&config->service_mtx);
+		return -1;
 	}
 	pthread_mutex_unlock(&config->service_mtx);
 
