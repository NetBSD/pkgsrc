$NetBSD: patch-src_wayland-os.h,v 1.3 2020/01/05 19:30:48 nia Exp $

https://lists.freedesktop.org/archives/wayland-devel/2019-February/040024.html

--- src/wayland-os.h.orig	2019-03-21 00:55:25.000000000 +0000
+++ src/wayland-os.h
@@ -35,8 +35,15 @@ wl_os_dupfd_cloexec(int fd, long minfd);
 ssize_t
 wl_os_recvmsg_cloexec(int sockfd, struct msghdr *msg, int flags);
 
+#ifdef HAVE_SYS_EPOLL_H
 int
 wl_os_epoll_create_cloexec(void);
+#endif
+
+#ifdef HAVE_SYS_EVENT_H
+int
+wl_os_queue_create_cloexec(void);
+#endif
 
 int
 wl_os_accept_cloexec(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
