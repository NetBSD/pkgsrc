$NetBSD: patch-ntpd_ntp__io.c,v 1.3 2020/06/21 15:10:47 taca Exp $

* Changes from NetBSD base.

--- ntpd/ntp_io.c.orig	2020-03-03 23:41:29.000000000 +0000
+++ ntpd/ntp_io.c
@@ -4836,6 +4836,50 @@ init_async_notifications()
 #else
 	int fd = socket(PF_ROUTE, SOCK_RAW, 0);
 #endif
+#ifdef RO_MSGFILTER
+	unsigned char msgfilter[] = {
+#ifdef RTM_NEWADDR
+		RTM_NEWADDR,
+#endif
+#ifdef RTM_DELADDR
+		RTM_DELADDR,
+#endif
+#ifdef RTM_ADD
+		RTM_ADD,
+#endif
+#ifdef RTM_DELETE
+		RTM_DELETE,
+#endif
+#ifdef RTM_REDIRECT
+		RTM_REDIRECT,
+#endif
+#ifdef RTM_CHANGE
+		RTM_CHANGE,
+#endif
+#ifdef RTM_LOSING
+		RTM_LOSING,
+#endif
+#ifdef RTM_IFINFO
+		RTM_IFINFO,
+#endif
+#ifdef RTM_IFANNOUNCE
+		RTM_IFANNOUNCE,
+#endif
+#ifdef RTM_NEWLINK
+		RTM_NEWLINK,
+#endif
+#ifdef RTM_DELLINK
+		RTM_DELLINK,
+#endif
+#ifdef RTM_NEWROUTE
+		RTM_NEWROUTE,
+#endif
+#ifdef RTM_DELROUTE
+		RTM_DELROUTE,
+#endif
+	};
+#endif /* !RO_MSGFILTER */
+
 	if (fd < 0) {
 		msyslog(LOG_ERR,
 			"unable to open routing socket (%m) - using polled interface update");
@@ -4856,6 +4900,11 @@ init_async_notifications()
 		return;
 	}
 #endif
+#ifdef RO_MSGFILTER
+	if (setsockopt(fd, PF_ROUTE, RO_MSGFILTER,
+	    &msgfilter, sizeof(msgfilter)) == -1)
+		msyslog(LOG_ERR, "RO_MSGFILTER: %m");
+#endif
 	make_socket_nonblocking(fd);
 #if defined(HAVE_SIGNALED_IO)
 	init_socket_sig(fd);
