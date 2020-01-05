$NetBSD: patch-src_wayland-os.c,v 1.3 2020/01/05 19:30:48 nia Exp $

https://lists.freedesktop.org/archives/wayland-devel/2019-February/040024.html

--- src/wayland-os.c.orig	2019-03-21 00:55:25.000000000 +0000
+++ src/wayland-os.c
@@ -30,9 +30,17 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <errno.h>
-#include <sys/epoll.h>
 
 #include "../config.h"
+
+#ifdef HAVE_SYS_EPOLL_H
+#include <sys/epoll.h>
+#endif
+
+#ifdef HAVE_SYS_EVENT_H
+#include <sys/event.h>
+#endif
+
 #include "wayland-os.h"
 
 static int
@@ -132,6 +140,7 @@ wl_os_recvmsg_cloexec(int sockfd, struct
 	return recvmsg_cloexec_fallback(sockfd, msg, flags);
 }
 
+#ifdef HAVE_SYS_EPOLL_H
 int
 wl_os_epoll_create_cloexec(void)
 {
@@ -148,6 +157,18 @@ wl_os_epoll_create_cloexec(void)
 	fd = epoll_create(1);
 	return set_cloexec_or_close(fd);
 }
+#endif
+
+#ifdef HAVE_SYS_EVENT_H
+int
+wl_os_queue_create_cloexec(void)
+{
+	int fd;
+
+	fd = kqueue();
+	return set_cloexec_or_close(fd);
+}
+#endif
 
 int
 wl_os_accept_cloexec(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
