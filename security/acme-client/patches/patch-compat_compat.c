$NetBSD: patch-compat_compat.c,v 1.1 2026/11/15 15:02:42 vins Exp $

Provide a compat wrapper for explicit_bzero(). 

--- compat/compat.c.orig	2026-10-10 11:50:17.000000000 +0000
+++ compat/compat.c
@@ -14,6 +14,25 @@
  */
 #define MUL_NO_OVERFLOW ((size_t)1 << (sizeof(size_t) * 4))
 
+#if !HAVE_EXPLICIT_BZERO
+/*
+ * From openbsd
+ *     commit: f5d2eefeb6c492f8ab3e752fb0b086496271977f
+ *     file  : ‎sys/lib/libkern/explicit_bzero.c
+ * Slightly modified.
+ */
+
+void
+explicit_bzero(void *buf, size_t len)
+{
+#if defined(__NetBSD__)
+	explicit_memset(buf, 0, len);
+#else
+	memset(buf, 0, len);
+#endif
+}
+#endif
+
 #if !HAVE_FREEZERO
 void
 freezero(void *ptr, size_t size)
