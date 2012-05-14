$NetBSD: patch-src_lib_network.c,v 1.1 2012/05/14 14:04:59 taca Exp $

* Add support for net_getunixcred() to NetBSD before 5.0 which dosen't
  have getpeereid(3); no LOCAL_PEEREID socket options.

--- src/lib/network.c.orig	2012-03-26 13:59:30.000000000 +0000
+++ src/lib/network.c
@@ -37,6 +37,10 @@ union sockaddr_union_unix {
 #  define SIZEOF_SOCKADDR(so) (sizeof(so.sin))
 #endif
 
+#if !defined(HAVE_GETPEEREID) && !defined(SO_PEERCRED) && !defined(HAVE_GETPEERUCRED) && defined(MSG_WAITALL) && defined(LOCAL_CREDS)
+#  define NEEDS_LOCAL_CREDS 1
+#endif
+
 bool net_ip_compare(const struct ip_addr *ip1, const struct ip_addr *ip2)
 {
 	return net_ip_cmp(ip1, ip2) == 0;
@@ -298,6 +302,16 @@ int net_connect_unix(const char *path)
 		return -1;
 	}
 
+#ifdef NEEDS_LOCAL_CREDS
+	{
+		int on = 1;
+		if (setsockopt(fd, 0, LOCAL_CREDS, &on, sizeof on)) {
+			i_error("setsockopt(LOCAL_CREDS) failed: %m");
+			return -1;
+		}
+	}
+#endif
+
 	return fd;
 }
 
@@ -454,6 +468,16 @@ int net_listen_unix(const char *path, in
 		return -1;
 	}
 
+#ifdef NEEDS_LOCAL_CREDS
+	{
+		int on = 1;
+		if (setsockopt(fd, 0, LOCAL_CREDS, &on, sizeof on)) {
+			i_error("setsockopt(LOCAL_CREDS) failed: %m");
+			return -1;
+		}
+	}
+#endif
+
 	/* bind */
 	if (bind(fd, &sa.sa, sizeof(sa)) < 0) {
 		if (errno != EADDRINUSE)
@@ -731,6 +755,44 @@ int net_getunixcred(int fd, struct net_u
 		return -1;
 	}
 	return 0;
+#elif NEEDS_LOCAL_CREDS
+	/* NetBSD < 5 */
+	int i, n, on;
+	struct iovec iov;
+	struct msghdr msg;
+	struct {
+		struct cmsghdr ch;
+		char buf[110];
+	} cdata;
+	struct sockcred *sc;
+
+	iov.iov_base = (char *)&on;
+	iov.iov_len = 1;
+
+	sc = (struct sockcred *)cdata.buf;
+	sc->sc_uid = sc->sc_euid = sc->sc_gid = sc->sc_egid = -1;
+	memset(&cdata.ch, 0, sizeof cdata.ch);
+
+	memset(&msg, 0, sizeof msg);
+
+	msg.msg_iov = &iov;
+	msg.msg_iovlen = 1;
+	msg.msg_control = &cdata;
+	msg.msg_controllen = sizeof(cdata.ch) + sizeof(cdata.buf);
+
+	for (i = 0; i < 10; i++) {
+		n = recvmsg(fd, &msg, MSG_WAITALL | MSG_PEEK);
+		if (n >= 0 || errno != EAGAIN)
+			break;
+		usleep(100);
+	}
+	if (n < 0) {
+		i_error("recvmsg() failed: %m");
+		return -1;
+	}
+	cred_r->uid = sc->sc_euid;
+	cred_r->gid = sc->sc_egid;
+	return 0;
 #else
 	errno = EINVAL;
 	return -1;
