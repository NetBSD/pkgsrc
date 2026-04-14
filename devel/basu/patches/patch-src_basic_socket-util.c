$NetBSD: patch-src_basic_socket-util.c,v 1.1 2026/04/14 10:58:10 kikadf Exp $

* NetBSD support
* Fix getpeercred on NetBSD

--- src/basic/socket-util.c.orig	2022-12-16 11:13:02.000000000 +0100
+++ src/basic/socket-util.c
@@ -8,6 +8,8 @@
 #ifdef __FreeBSD__
 #include <sys/ucred.h>
 #include <sys/un.h>
+#elif defined(__NetBSD__)
+#include <sys/un.h>
 #endif
 
 int fd_inc_sndbuf(int fd, size_t n) {
@@ -47,6 +49,27 @@ int getpeercred(int fd, struct ucred *uc
         };
 
         *ucred = u;
+#elif defined(__NetBSD__)
+        struct unpcbid cred;
+        socklen_t len = sizeof(cred);
+
+        assert(fd >= 0);
+        assert(ucred);
+
+        if (getsockopt(fd, 0, LOCAL_PEEREID, &cred, &len) == -1) {
+                return -errno;
+        }
+
+        struct ucred u = {
+                .pid = -1,
+                .uid = cred.unp_euid,
+                .gid = cred.unp_egid,
+        };
+
+        if (len != sizeof(cred))
+                return -EIO;
+
+        *ucred = u;
 #else
         socklen_t n = sizeof(struct ucred);
         struct ucred u;
@@ -75,7 +98,7 @@ int getpeercred(int fd, struct ucred *uc
 }
 
 int getpeersec(int fd, char **ret) {
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
         return -EOPNOTSUPP;
 #else
         _cleanup_free_ char *s = NULL;
