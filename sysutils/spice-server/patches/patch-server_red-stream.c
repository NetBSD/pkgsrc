$NetBSD: patch-server_red-stream.c,v 1.1 2020/02/06 21:57:42 kamil Exp $

Add NetBSD support.

--- server/red-stream.c.orig	2019-04-30 08:51:11.000000000 +0000
+++ server/red-stream.c
@@ -27,6 +27,9 @@
 #include <sys/socket.h>
 #include <netinet/tcp.h>
 #endif
+#ifdef __NetBSD__
+#include <netinet/in.h>
+#endif
 
 #include <glib.h>
 
@@ -109,7 +112,11 @@ struct RedStreamPrivate {
 static int socket_set_cork(int socket, int enabled)
 {
     SPICE_VERIFY(sizeof(enabled) == sizeof(int));
+#if defined(__NetBSD__)
+    return 1; /* Not supported */
+#else
     return setsockopt(socket, IPPROTO_TCP, TCP_CORK, &enabled, sizeof(enabled));
+#endif
 }
 
 static ssize_t stream_write_cb(RedStream *s, const void *buf, size_t size)
