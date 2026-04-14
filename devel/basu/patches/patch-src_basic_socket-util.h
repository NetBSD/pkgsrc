$NetBSD: patch-src_basic_socket-util.h,v 1.1 2026/04/14 10:58:10 kikadf Exp $

* Use own ucred struct on NetBSD

--- src/basic/socket-util.h.orig	2022-12-16 11:13:02.000000000 +0100
+++ src/basic/socket-util.h
@@ -29,6 +29,12 @@ struct ucred {
         uint32_t uid;
         uint32_t gid;
 };
+#elif defined(__NetBSD__)
+struct ucred {
+        pid_t pid;
+        uid_t uid;
+        gid_t gid;
+};
 #endif
 
 int fd_inc_sndbuf(int fd, size_t n);
