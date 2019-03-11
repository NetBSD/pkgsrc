$NetBSD: patch-pledge.c,v 1.1 2019/03/11 16:27:03 kamil Exp $

Add a fallback implementation of OpenBSD specific function.

--- pledge.c.orig	2019-03-11 16:01:37.907598032 +0000
+++ pledge.c
@@ -0,0 +1,8 @@
+#ifndef __OpenBSD__
+int
+pledge(const char *promises, const char *execpromises)
+{
+
+	return 0;
+}
+#endif
