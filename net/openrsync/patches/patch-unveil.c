$NetBSD: patch-unveil.c,v 1.1 2019/03/11 16:27:03 kamil Exp $

Add a fallback implementation of OpenBSD specific function.

--- unveil.c.orig	2019-03-11 16:01:37.907822028 +0000
+++ unveil.c
@@ -0,0 +1,8 @@
+#ifndef __OpenBSD__
+int
+unveil(const char *path, const char *permissions)
+{
+
+	return 0;
+}
+#endif
