$NetBSD: patch-mono_utils_mono-threads-freebsd.c,v 1.1 2014/11/30 08:40:51 spz Exp $

--- mono/utils/mono-threads-freebsd.c.orig	2014-09-22 13:23:09.000000000 +0000
+++ mono/utils/mono-threads-freebsd.c
@@ -2,14 +2,14 @@
 
 #if defined(__FreeBSD__)
 
+#include <mono/utils/mono-threads.h>
 #include <pthread.h>
 #include <pthread_np.h>
 
 void
 mono_threads_core_get_stack_bounds (guint8 **staddr, size_t *stsize)
 {
 	pthread_attr_t attr;
-	guint8 *current = (guint8*)&attr;
 
 	*staddr = NULL;
 	*stsize = (size_t)-1;
