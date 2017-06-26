$NetBSD: patch-parpd.c,v 1.1 2017/06/26 09:59:16 manu Exp $

Submitted upstream as https://dev.marples.name/T127

From 63d9d122d83dc358c6180d52187026f099ab6389 Mon Sep 17 00:00:00 2001
From: Emmanuel Dreyfus <manu@netbsd.org>
Date: Mon, 26 Jun 2017 11:38:39 +0200
Subject: [PATCH] Fix kqueue usage when forking in the background

NetBSD's kqueue(2) man page says "The queue is not inherited by a
child created with fork(2)", which means the poll_fd needs to be
reopen after forking in the background.

This is done by calling eloop_requeue() after daemon().
---
 parpd.c | 14 +++++++++++---
 1 file changed, 11 insertions(+), 3 deletions(-)

diff --git parpd.c parpd.c
index a178696..dbf26c4 100644
--- parpd.c
+++ parpd.c
@@ -718,9 +718,17 @@ main(int argc, char **argv)
 		goto out;
 	}
 
-	if (!fflag && daemon(0, 0) == -1) {
-		syslog(LOG_ERR, "daemon: %m");
-		goto out;
+	if (!fflag) {
+		if (daemon(0, 0) == -1) {
+			syslog(LOG_ERR, "daemon: %m");
+			goto out;
+		}
+
+		/* At least for kqueue, poll_fd gets invalidated by fork */
+                if (eloop_requeue(eloop) == -1) {
+                        syslog(LOG_ERR, "eloop_requeue after fork: %m");
+                        goto out;
+                }
 	}
 
 	opt = eloop_start(eloop, &sigset);
-- 
2.11.0

