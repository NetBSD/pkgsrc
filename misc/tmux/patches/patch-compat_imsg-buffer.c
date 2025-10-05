$NetBSD: patch-compat_imsg-buffer.c,v 1.2 2025/10/05 11:04:21 leot Exp $

Add support for QNX.

--- compat/imsg-buffer.c.orig	2024-01-17 10:56:43.000000000 +0000
+++ compat/imsg-buffer.c
@@ -45,6 +45,10 @@
 #undef be64toh
 #define be64toh ntohll
 
+#if defined(__QNX__) && !defined(IOV_MAX)
+# define IOV_MAX 16
+#endif
+
 static int	ibuf_realloc(struct ibuf *, size_t);
 static void	ibuf_enqueue(struct msgbuf *, struct ibuf *);
 static void	ibuf_dequeue(struct msgbuf *, struct ibuf *);
