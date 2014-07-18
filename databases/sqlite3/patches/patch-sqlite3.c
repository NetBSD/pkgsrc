$NetBSD: patch-sqlite3.c,v 1.3 2014/07/18 11:25:14 ryoon Exp $

--- sqlite3.c.orig	2014-02-11 19:42:03.000000000 +0000
+++ sqlite3.c
@@ -25,6 +25,11 @@
 #ifndef SQLITE_API
 # define SQLITE_API
 #endif
+/* GNU pth requires these headers in very early stage. */
+#if defined(_SCO_DS)
+#include <sys/types.h>
+#include <sys/stat.h>
+#endif
 /************** Begin file sqlite3.h *****************************************/
 /*
 ** 2001 September 15
