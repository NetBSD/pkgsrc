$NetBSD: patch-src_libsystemd_sd-bus_bus-socket.c,v 1.1 2026/04/14 10:58:10 kikadf Exp $

* Fix logging, on NetBSD %m is only allowed in syslog(3) like function
* sendmsg() with a SOL_SOCKET/SCM_CREDS message EINVAL on NetBSD


--- src/libsystemd/sd-bus/bus-socket.c.orig	2022-12-16 11:13:02.000000000 +0100
+++ src/libsystemd/sd-bus/bus-socket.c
@@ -20,6 +20,11 @@
 #include "user-util.h"
 #include "utf8.h"
 
+#if defined(__NetBSD__)
+#include <sys/un.h>
+#include <sys/socket.h>
+#endif
+
 #define SNDBUF_SIZE (8*1024*1024)
 
 static void iovec_advance(struct iovec iov[], unsigned *idx, size_t size) {
@@ -119,6 +124,9 @@ bool bus_socket_auth_needs_write(sd_bus 
 }
 
 static int bus_socket_write_null_byte(sd_bus *b) {
+        struct msghdr mh;
+        zero(mh);
+
 #if defined(__linux__)
 #define SOCKET_CRED_OPTION SCM_CREDENTIALS
         struct ucred creds;
@@ -129,19 +137,20 @@ static int bus_socket_write_null_byte(sd
 #elif defined(__FreeBSD__)
 #define SOCKET_CRED_OPTION SCM_CREDS
         struct cmsgcred creds = { 0 };
+#elif defined(__NetBSD__)
+        mh.msg_control = NULL;
+        mh.msg_controllen = 0;
 #else
 #error auth not implemented for this OS
 #endif
 
+#if !defined(__NetBSD__)
         union {
                 struct cmsghdr hdr;
                 uint8_t buf[CMSG_SPACE(sizeof(creds))];
         } control;
         memset(control.buf, 0, sizeof(control.buf));
 
-        struct msghdr mh;
-        zero(mh);
-
         mh.msg_control = control.buf;
         mh.msg_controllen = sizeof(control.buf);
 
@@ -150,6 +159,7 @@ static int bus_socket_write_null_byte(sd
         cmsgp->cmsg_level = SOL_SOCKET;
         cmsgp->cmsg_type = SOCKET_CRED_OPTION;
         memcpy(CMSG_DATA(cmsgp), &creds, sizeof(creds));
+#endif
 
         struct iovec iov;
         mh.msg_iov = &iov;
@@ -617,7 +627,7 @@ static int bus_socket_read_auth(sd_bus *
                         log_debug("Got unexpected auxiliary data with level=%d and type=%d",
                                   cmsg->cmsg_level, cmsg->cmsg_type);
                 else if (r < 0)
-                        log_error_errno(r, "Could not process credentials: %m");
+                        log_error_errno(r, "Could not process credentials");
         }
 
         r = bus_socket_auth_verify(b);
@@ -650,7 +660,7 @@ static void bus_get_peercred(sd_bus *b) 
         int optval = 1;
         r = setsockopt(b->output_fd, SOL_SOCKET, SO_PASSCRED, &optval, sizeof(optval));
         if (r < 0)
-                log_debug_errno(r, "Failed to set SO_PASSCRED: %m");
+                log_debug_errno(r, "Failed to set SO_PASSCRED");
 #endif
 
         /* Get the peer for socketpair() sockets */
@@ -659,14 +669,14 @@ static void bus_get_peercred(sd_bus *b) 
         /* Get the SELinux context of the peer */
         r = getpeersec(b->input_fd, &b->label);
         if (r < 0 && !IN_SET(r, -EOPNOTSUPP, -ENOPROTOOPT))
-                log_debug_errno(r, "Failed to determine peer security context: %m");
+                log_debug_errno(r, "Failed to determine peer security context");
 
         /* Get the list of auxiliary groups of the peer */
         r = getpeergroups(b->input_fd, &b->groups);
         if (r >= 0)
                 b->n_groups = (size_t) r;
         else if (!IN_SET(r, -EOPNOTSUPP, -ENOPROTOOPT))
-                log_debug_errno(r, "Failed to determine peer's group list: %m");
+                log_debug_errno(r, "Failed to determine peer's group list");
 }
 
 static int bus_socket_start_auth_client(sd_bus *b) {
