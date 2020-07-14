$NetBSD: patch-tc.alloc.c,v 1.3 2020/07/14 21:48:30 christos Exp $

Fix static linking since NetBSD's libc needs these for pthread_atfork();

--- tc.alloc.c.orig	2019-12-04 12:51:54.000000000 -0500
+++ tc.alloc.c	2020-07-14 17:42:39.103744313 -0400
@@ -655,3 +655,13 @@
     USE(c);
     USE(v);
 }
+
+#ifndef SYSMALLOC
+/* jemalloc defines these */
+void _malloc_prefork(void);
+void _malloc_postfork(void);
+void _malloc_postfork_child(void);
+void _malloc_prefork(void) {}
+void _malloc_postfork(void) {}
+void _malloc_postfork_child(void) {}
+#endif
