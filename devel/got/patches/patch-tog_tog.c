$NetBSD: patch-tog_tog.c,v 1.1 2021/01/29 20:35:11 ryoon Exp $

--- tog/tog.c.orig	2020-12-27 09:14:30.000000000 +0000
+++ tog/tog.c
@@ -20,9 +20,13 @@
 
 #include <ctype.h>
 #include <errno.h>
+#if !defined(_XOPEN_SOURCE_EXTENDED)
 #define _XOPEN_SOURCE_EXTENDED
+#endif
 #include <curses.h>
+#if !defined(_XOPEN_SOURCE_EXTENDED)
 #undef _XOPEN_SOURCE_EXTENDED
+#endif
 #include <panel.h>
 #include <locale.h>
 #include <signal.h>
@@ -838,7 +842,11 @@ view_input(struct tog_view **new, int *d
 		if (errcode)
 			return got_error_set_errno(errcode,
 			    "pthread_mutex_unlock");
+#if defined(__NetBSD__)
+		sched_yield();
+#else
 		pthread_yield();
+#endif
 		errcode = pthread_mutex_lock(&tog_mutex);
 		if (errcode)
 			return got_error_set_errno(errcode,
