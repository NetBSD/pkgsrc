$NetBSD: patch-compat_imsg-buffer.c,v 1.3 2026/01/18 20:30:49 wiz Exp $

Add support for QNX.

--- compat/imsg-buffer.c.orig	2025-06-24 14:04:21.000000000 +0000
+++ compat/imsg-buffer.c
@@ -45,6 +45,10 @@
 #undef be64toh
 #define be64toh ntohll
 
+#if defined(__QNX__) && !defined(IOV_MAX)
+# define IOV_MAX 16
+#endif
+
 struct ibufqueue {
 	TAILQ_HEAD(, ibuf)	bufs;
 	uint32_t		queued;
