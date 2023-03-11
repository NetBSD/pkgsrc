$NetBSD: patch-cfs__attach.c,v 1.2 2023/03/11 01:54:01 gdt Exp $

For NetBSD, use statvfs.

\todo Send upstream.

--- cattach.c.orig	2013-05-15 16:50:30.000000000 +0000
+++ cattach.c
@@ -59,6 +59,12 @@
   your solaris configuration */
 #define statfs		statvfs
 #endif
+#ifdef NetBSD
+/*
+ * Strictly, NetBSD >= 3.0.
+ */
+#define statfs         statvfs
+#endif
 
 #ifndef TMOUT		/* default timeout; override in makefile */
 #define TMOUT 0
