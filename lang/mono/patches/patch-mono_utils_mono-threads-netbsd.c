$NetBSD: patch-mono_utils_mono-threads-netbsd.c,v 1.1 2014/11/30 08:40:51 spz Exp $

--- mono/utils/mono-threads-netbsd.c.orig	2014-11-29 21:20:20.000000000 +0000
+++ mono/utils/mono-threads-netbsd.c
@@ -0,0 +1,23 @@
+#include <config.h>
+
+#if defined(__NetBSD__)
+
+#include <mono/utils/mono-threads.h>
+#include <pthread.h>
+
+void
+mono_threads_core_get_stack_bounds (guint8 **staddr, size_t *stsize)
+{
+	pthread_attr_t attr;
+
+	*staddr = NULL;
+	*stsize = (size_t)-1;
+
+	pthread_attr_init (&attr);
+	pthread_attr_get_np (pthread_self (), &attr);
+
+	pthread_attr_getstack (&attr, (void**)staddr, stsize);
+	pthread_attr_destroy (&attr);
+}
+
+#endif
