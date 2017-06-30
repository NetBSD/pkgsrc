$NetBSD: patch-fscd_fscd.c,v 1.2 2017/06/30 00:25:34 kamil Exp $

--- fscd/fscd.c.orig	2012-11-12 00:12:33.000000000 +0000
+++ fscd/fscd.c
@@ -45,7 +45,9 @@ __FBSDID("$FreeBSD$");
 #include <sys/sysctl.h>
 #include <sys/uio.h>
 #include <sys/un.h>
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/user.h>
+#endif
 #include <sys/time.h>
 #include <sys/wait.h>
 #include <ctype.h>
@@ -1067,6 +1069,10 @@ handle_task(struct fscd_cfg *config, cha
 		print_status(config, sock_fd);
 		pthread_mutex_unlock(&config->service_mtx);
 		return 0;
+	} else {
+		printlog(LOG_ERR, "received invalid message from client.");
+		pthread_mutex_unlock(&config->service_mtx);
+		return -1;
 	}
 	pthread_mutex_unlock(&config->service_mtx);
 
