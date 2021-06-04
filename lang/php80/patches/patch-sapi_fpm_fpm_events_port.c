$NetBSD: patch-sapi_fpm_fpm_events_port.c,v 1.2 2021/06/04 13:56:31 taca Exp $

Similar to upstream bug #65800. We should resubmit this patch and
get that bugfix intergrated, by changing port_associate() call to
use the wrapper fpm_event_port_add().

--- sapi/fpm/fpm/events/port.c.orig	2021-06-01 18:43:05.000000000 +0000
+++ sapi/fpm/fpm/events/port.c
@@ -145,14 +145,23 @@ static int fpm_event_port_wait(struct fp
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
