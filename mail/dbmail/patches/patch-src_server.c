$NetBSD: patch-src_server.c,v 1.1 2026/09/07 21:26:43 tnn Exp $

https://github.com/dbmail/dbmail/commit/0ea3c1aff8d9af22a1f5f39d4f825ffb4b071908

--- src/server.c.orig	2026-08-22 19:36:08.156416568 +0000
+++ src/server.c
@@ -81,12 +81,13 @@ static void cb_queue_drain(int fd, short what UNUSED, 
 static void cb_queue_drain(int fd, short what UNUSED, void *arg UNUSED)
 {
 	char buf[1024];
-	event_del(heartbeat);
-	dm_queue_drain();
+	ssize_t r;
 	PLOCK(selfpipe_lock);
-	if (read(fd, buf, sizeof(buf))) { /* ignore */ }
+	do {
+		r = read(fd, buf, sizeof(buf));
+	} while (r == sizeof(buf));
 	PUNLOCK(selfpipe_lock);
-	event_add(heartbeat, NULL);
+	dm_queue_drain();
 }
 
 
@@ -100,7 +101,7 @@ void dm_queue_heartbeat(void)
 
 	pthread_mutex_init(&selfpipe_lock, NULL);
 
-	heartbeat = event_new(evbase, selfpipe[0], EV_READ, cb_queue_drain, NULL);
+	heartbeat = event_new(evbase, selfpipe[0], EV_READ|EV_PERSIST, cb_queue_drain, NULL);
 	event_add(heartbeat, NULL);
 }
 
