$NetBSD: patch-openbsd-compat_explicit__bzero.c,v 1.1 2023/09/03 13:00:43 vins Exp $

Use explicit_memset() on NetBSD. 

--- openbsd-compat/explicit_bzero.c.orig	2019-11-14 18:23:50.000000000 +0000
+++ openbsd-compat/explicit_bzero.c
@@ -11,5 +11,9 @@
 void
 explicit_bzero(void *buf, size_t len)
 {
+#if defined(__NetBSD__)
+	explicit_memset(buf, 0, len);
+#else
 	memset(buf, 0, len);
+#endif
 }
