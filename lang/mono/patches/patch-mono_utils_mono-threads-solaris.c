$NetBSD: patch-mono_utils_mono-threads-solaris.c,v 1.1 2014/11/30 08:40:51 spz Exp $

--- mono/utils/mono-threads-solaris.c.orig	2014-11-29 21:53:35.000000000 +0000
+++ mono/utils/mono-threads-solaris.c
@@ -0,0 +1,19 @@
+#include <config.h>
+
+#if defined(PLATFORM_SOLARIS)
+
+#include <mono/utils/mono-threads.h>
+#include <pthread.h>
+
+void
+mono_threads_core_get_stack_bounds (guint8 **staddr, size_t *stsize)
+{
+	pthread_attr_t attr;
+	pthread_attr_init (&attr);
+	pthread_attr_getstacksize (&attr, &stsize);
+	pthread_attr_destroy (&attr);
+	*staddr = NULL;
+	return;
+}
+
+#endif
