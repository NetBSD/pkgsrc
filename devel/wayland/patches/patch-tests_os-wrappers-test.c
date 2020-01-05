$NetBSD: patch-tests_os-wrappers-test.c,v 1.3 2020/01/05 19:30:48 nia Exp $

https://lists.freedesktop.org/archives/wayland-devel/2019-February/040024.html

--- tests/os-wrappers-test.c.orig	2019-03-21 00:55:25.000000000 +0000
+++ tests/os-wrappers-test.c
@@ -38,7 +38,16 @@
 #include <stdarg.h>
 #include <fcntl.h>
 #include <stdio.h>
+
+#include "../config.h"
+
+#ifdef HAVE_SYS_EPOLL_H
 #include <sys/epoll.h>
+#endif
+
+#ifdef HAVE_SYS_EVENT_H
+#include <sys/event.h>
+#endif
 
 #include "wayland-private.h"
 #include "test-runner.h"
@@ -55,8 +64,15 @@ static int wrapped_calls_fcntl;
 static ssize_t (*real_recvmsg)(int, struct msghdr *, int);
 static int wrapped_calls_recvmsg;
 
+#ifdef HAVE_SYS_EPOLL_H
 static int (*real_epoll_create1)(int);
 static int wrapped_calls_epoll_create1;
+#endif
+
+#ifdef HAVE_SYS_EVENT_H
+static int (*real_kqueue)(void);
+static int wrapped_calls_kqueue;
+#endif
 
 static void
 init_fallbacks(int do_fallbacks)
@@ -65,7 +81,12 @@ init_fallbacks(int do_fallbacks)
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
@@ -114,6 +135,7 @@ recvmsg(int sockfd, struct msghdr *msg, 
 	return real_recvmsg(sockfd, msg, flags);
 }
 
+#ifdef HAVE_SYS_EPOLL_H
 __attribute__ ((visibility("default"))) int
 epoll_create1(int flags)
 {
@@ -127,6 +149,23 @@ epoll_create1(int flags)
 
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
@@ -334,6 +373,7 @@ TEST(os_wrappers_recvmsg_cloexec_fallbac
 	do_os_wrappers_recvmsg_cloexec(1);
 }
 
+#ifdef HAVE_SYS_EPOLL_H
 static void
 do_os_wrappers_epoll_create_cloexec(int n)
 {
@@ -365,5 +405,34 @@ TEST(os_wrappers_epoll_create_cloexec_fa
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
