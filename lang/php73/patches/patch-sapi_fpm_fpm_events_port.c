$NetBSD: patch-sapi_fpm_fpm_events_port.c,v 1.1 2018/12/15 17:12:44 taca Exp $

Similar to upstream bug #65800. We should resubmit this patch and
get that bugfix intergrated, by changing port_associate() call to
use the wrapper fpm_event_port_add().

--- sapi/fpm/fpm/events/port.c.orig	2015-06-23 17:33:33.000000000 +0000
+++ sapi/fpm/fpm/events/port.c
@@ -124,6 +124,7 @@ static int fpm_event_port_wait(struct fp
 	t.tv_nsec = (timeout % 1000) * 1000 * 1000;
 
 	/* wait for inconming event or timeout. We want at least one event or timeout */
+again:
 	nget = 1;
 	ret = port_getn(pfd, events, nevents, &nget, &t);
 	if (ret < 0) {
@@ -133,17 +134,31 @@ static int fpm_event_port_wait(struct fp
 			zlog(ZLOG_WARNING, "poll() returns %d", errno);
 			return -1;
 		}
+
+		if (errno == EINTR)
+			goto again;
+
+		return 0;
 	}
 
 	for (i = 0; i < nget; i++) {
+		struct fpm_event_s *ev;
 
 		/* do we have a ptr to the event ? */
 		if (!events[i].portev_user) {
 			continue;
 		}
 
+		ev = (struct fpm_event_s *)events[i].portev_user;
+
+		if (port_associate(pfd, PORT_SOURCE_FD,
+		    ev->fd, POLLIN, (void *)ev) < 0) {
+			zlog(ZLOG_ERROR, "port: unable to add the event");
+			return -1;
+		}
+
 		/* fire the event */
-		fpm_event_fire((struct fpm_event_s *)events[i].portev_user);
+		fpm_event_fire(ev);
 
 		/* sanity check */
 		if (fpm_globals.parent_pid != getpid()) {
