$NetBSD: patch-compat_compat.h,v 1.1 2026/11/15 15:02:42 vins Exp $

Provide a prototype for explicit_bzero().

--- compat/compat.h.orig	2026-10-10 11:50:17.000000000 +0000
+++ compat/compat.h
@@ -16,6 +16,10 @@
 # define unveil(x, y) 0
 #endif
 
+#if !HAVE_EXPLICIT_BZERO
+void explicit_bzero(void *buf, size_t len);
+#endif
+
 #if !HAVE_FREEZERO
 void freezero(void *ptr, size_t size);
 #endif
