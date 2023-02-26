$NetBSD: patch-alpine_pine-use.c,v 1.1 2023/02/26 20:39:49 vins Exp $

Fix default user mailbox path.

--- alpine/pine-use.c.orig	2022-06-03 00:14:00.463274817 +0000
+++ alpine/pine-use.c
@@ -20,7 +20,11 @@
 #include <sys/stat.h>
 
 #ifndef MAILSPOOLPCTS
-#define MAILSPOOLPCTS "/usr/spool/mail/%s"
+#if defined(__linux__)
+# define MAILSPOOLPCTS "@VARBASE@/spool/mail/%s"
+#else
+# define MAILSPOOLPCTS "@VARBASE@/mail/%s"
+#endif
 /* #define MAILSPOOLPCTS "/usr/mail/%s" */
 #endif
 
