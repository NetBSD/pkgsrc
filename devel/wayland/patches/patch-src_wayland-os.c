$NetBSD: patch-src_wayland-os.c,v 1.4 2022/08/04 15:21:26 nia Exp $

Support for NetBSD.

--- src/wayland-os.c.orig	2022-06-30 21:59:11.000000000 +0000
+++ src/wayland-os.c
@@ -100,6 +100,24 @@ wl_os_socket_peercred(int sockfd, uid_t 
 #endif
 	return 0;
 }
+#elif defined(__NetBSD__)
+#ifndef SOL_LOCAL
+#define SOL_LOCAL (0)
+#endif
+int
+wl_os_socket_peercred(int sockfd, uid_t *uid, gid_t *gid, pid_t *pid)
+{
+	socklen_t len;
+	struct sockcred ucred;
+
+	len = sizeof(ucred);
+	if (getsockopt(sockfd, SOL_LOCAL, LOCAL_CREDS, &ucred, &len) < 0)
+		return -1;
+	*uid = ucred.sc_uid;
+	*gid = ucred.sc_gid;
+	*pid = 0;
+	return 0;
+}
 #elif defined(SO_PEERCRED)
 int
 wl_os_socket_peercred(int sockfd, uid_t *uid, gid_t *gid, pid_t *pid)
