$NetBSD: patch-logrotate.c,v 1.1.1.1 2012/03/06 04:53:24 sbd Exp $

Compatibility patch for systems not using alloca.h .
Patch commited upstream. 

--- logrotate.c.orig	2011-08-31 12:39:04.000000000 +0000
+++ logrotate.c
@@ -1,6 +1,9 @@
 #include <sys/queue.h>
+#ifdef _ALLOCA_H
 #include <alloca.h>
+#else
 #include <limits.h>
+#endif
 #include <ctype.h>
 #include <dirent.h>
 #include <errno.h>
