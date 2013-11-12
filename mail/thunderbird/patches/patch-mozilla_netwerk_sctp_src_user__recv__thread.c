$NetBSD: patch-mozilla_netwerk_sctp_src_user__recv__thread.c,v 1.1 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/netwerk/sctp/src/user_recv_thread.c.orig	2013-10-23 22:09:15.000000000 +0000
+++ mozilla/netwerk/sctp/src/user_recv_thread.c
@@ -35,7 +35,7 @@
 #include <netinet/in.h>
 #include <unistd.h>
 #include <pthread.h>
-#if !defined(__Userspace_os_FreeBSD)
+#if !defined(__Userspace_os_FreeBSD) && !defined(__Userspace_os_NetBSD)
 #include <sys/uio.h>
 #else
 #include <user_ip6_var.h>
