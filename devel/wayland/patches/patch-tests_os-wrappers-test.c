$NetBSD: patch-tests_os-wrappers-test.c,v 1.2 2019/08/29 12:22:13 nia Exp $

BSD support from FreeBSD

https://lists.freedesktop.org/archives/wayland-devel/2019-February/040024.html

--- tests/os-wrappers-test.c.orig	2019-03-21 00:55:25.000000000 +0000
+++ tests/os-wrappers-test.c
@@ -26,6 +26,8 @@
 
 #define _GNU_SOURCE
 
+#include "../config.h"
+
 #include <stdlib.h>
 #include <stdint.h>
 #include <assert.h>
@@ -38,7 +40,13 @@
 #include <stdarg.h>
 #include <fcntl.h>
 #include <stdio.h>
+
+#ifdef HAVE_SYS_EPOLL_H
 #include <sys/epoll.h>
+#endif
+#ifdef HAVE_SYS_EVENT_H
+#include <sys/event.h>
+#endif
 
 #include "wayland-private.h"
 #include "test-runner.h"
@@ -55,8 +63,14 @@ static int wrapped_calls_fcntl;
 static ssize_t (*real_recvmsg)(int, struct msghdr *, int);
 static int wrapped_calls_recvmsg;
 
+#ifdef HAVE_SYS_EPOLL_H
 static int (*real_epoll_create1)(int);
 static int wrapped_calls_epoll_create1;
+#endif
+#ifdef HAVE_SYS_EVENT_H
+static int (*real_kqueue)(void);
+static int wrapped_calls_kqueue;
+#endif
 
 static void
 init_fallbacks(int do_fallbacks)
@@ -65,7 +79,12 @@ init_fallbacks(int do_fallbacks)
 	real_socket = dlsym(RTLD_NEXT, "socket");
 	real_fcntl = dlsym(RTLD_NEXT, "fcntl");
 	real_recvmsg = dlsym(RTLD_NEXT, "recvmsg");
+#ifdef HAVE_SYS_EPOLL_H
 	real_epoll_create1 = dlsym(RTLD_NEXT, "epoll_create1");
+#endif
+#ifdef HAVE_SYS_EVENT_H
+	real_kqueue = dlsym(RTLD_NEXT, "kqueue");
+#endif
 }
 
 __attribute__ ((visibility("default"))) int
@@ -73,10 +92,12 @@ socket(int domain, int type, int protoco
 {
 	wrapped_calls_socket++;
 
+#ifdef SOCK_CLOEXEC
 	if (fall_back && (type & SOCK_CLOEXEC)) {
 		errno = EINVAL;
 		return -1;
 	}
+#endif
 
 	return real_socket(domain, type, protocol);
 }
@@ -89,10 +110,12 @@ fcntl(int fd, int cmd, ...)
 
 	wrapped_calls_fcntl++;
 
+#ifdef F_DUPFD_CLOEXEC
 	if (fall_back && (cmd == F_DUPFD_CLOEXEC)) {
 		errno = EINVAL;
 		return -1;
 	}
+#endif
 
 	va_start(ap, cmd);
 	arg = va_arg(ap, void*);
@@ -106,14 +129,17 @@ recvmsg(int sockfd, struct msghdr *msg, 
 {
 	wrapped_calls_recvmsg++;
 
+#ifdef MSG_CMSG_CLOEXEC
 	if (fall_back && (flags & MSG_CMSG_CLOEXEC)) {
 		errno = EINVAL;
 		return -1;
 	}
+#endif
 
 	return real_recvmsg(sockfd, msg, flags);
 }
 
+#ifdef HAVE_SYS_EPOLL_H
 __attribute__ ((visibility("default"))) int
 epoll_create1(int flags)
 {
@@ -127,6 +153,23 @@ epoll_create1(int flags)
 
 	return real_epoll_create1(flags);
 }
+#endif
+
+#ifdef HAVE_SYS_EVENT_H
+__attribute__ ((visibility("default"))) int
+kqueue(void)
+{
+	wrapped_calls_kqueue++;
+
+	if (fall_back) {
+		wrapped_calls_kqueue++; /* kqueue() not wrapped */
+		errno = EINVAL;
+		return -1;
+	}
+
+	return real_kqueue();
+}
+#endif
 
 static void
 do_os_wrappers_socket_cloexec(int n)
@@ -156,12 +199,14 @@ TEST(os_wrappers_socket_cloexec)
 	do_os_wrappers_socket_cloexec(0);
 }
 
+#ifdef SOCK_CLOEXEC
 TEST(os_wrappers_socket_cloexec_fallback)
 {
 	/* forced fallback */
 	init_fallbacks(1);
 	do_os_wrappers_socket_cloexec(1);
 }
+#endif
 
 static void
 do_os_wrappers_dupfd_cloexec(int n)
@@ -195,11 +240,13 @@ TEST(os_wrappers_dupfd_cloexec)
 	do_os_wrappers_dupfd_cloexec(0);
 }
 
+#ifdef F_DUPFD_CLOEXEC
 TEST(os_wrappers_dupfd_cloexec_fallback)
 {
 	init_fallbacks(1);
 	do_os_wrappers_dupfd_cloexec(3);
 }
+#endif
 
 struct marshal_data {
 	struct wl_connection *read_connection;
@@ -218,8 +265,7 @@ struct marshal_data {
 static void
 setup_marshal_data(struct marshal_data *data)
 {
-	assert(socketpair(AF_UNIX,
-			  SOCK_STREAM | SOCK_CLOEXEC, 0, data->s) == 0);
+	assert(wl_os_socketpair_cloexec(AF_UNIX, SOCK_STREAM, 0, data->s) == 0);
 
 	data->read_connection = wl_connection_create(data->s[0]);
 	assert(data->read_connection);
@@ -328,12 +374,15 @@ TEST(os_wrappers_recvmsg_cloexec)
 	do_os_wrappers_recvmsg_cloexec(0);
 }
 
+#ifdef MSG_CMSG_CLOEXEC
 TEST(os_wrappers_recvmsg_cloexec_fallback)
 {
 	init_fallbacks(1);
 	do_os_wrappers_recvmsg_cloexec(1);
 }
+#endif
 
+#ifdef HAVE_SYS_EPOLL_H
 static void
 do_os_wrappers_epoll_create_cloexec(int n)
 {
@@ -365,5 +414,34 @@ TEST(os_wrappers_epoll_create_cloexec_fa
 	init_fallbacks(1);
 	do_os_wrappers_epoll_create_cloexec(2);
 }
+#endif
+
+#ifdef HAVE_SYS_EVENT_H
+static void
+do_os_wrappers_queue_create_cloexec(int n)
+{
+	int fd;
+	int nr_fds;
+
+	nr_fds = count_open_fds();
+
+	fd = wl_os_queue_create_cloexec();
+	assert(fd >= 0);
+
+	exec_fd_leak_check(nr_fds);
+}
+
+TEST(os_wrappers_queue_create_cloexec)
+{
+	init_fallbacks(0);
+	do_os_wrappers_queue_create_cloexec(1);
+}
+
+TEST(os_wrappers_queue_create_cloexec_fallback)
+{
+	init_fallbacks(1);
+	do_os_wrappers_queue_create_cloexec(2);
+}
+#endif
 
 /* FIXME: add tests for wl_os_accept_cloexec() */
