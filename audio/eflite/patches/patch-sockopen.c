$NetBSD: patch-sockopen.c,v 1.1 2024/02/25 22:00:09 wiz Exp $

Add string.h inclusion when needed

--- sockopen.c.orig	2024-01-14 23:55:06.000000000 +0000
+++ sockopen.c
@@ -11,6 +11,9 @@
 #include <sys/stat.h>
 #include <sys/un.h>
 #include <syslog.h>
+#ifdef HAVE_STRING_H
+# include <string.h>
+#endif
 
 int sockopen_unix(const char *fname)
 {
