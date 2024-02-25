$NetBSD: patch-soccon.c,v 1.1 2024/02/25 22:00:09 wiz Exp $

Add string.h inclusion when needed

--- soccon.c.orig	2024-01-14 23:55:06.000000000 +0000
+++ soccon.c
@@ -10,6 +10,9 @@
 #include <arpa/inet.h>
 #include <sys/un.h>
 #include <unistd.h>
+#ifdef HAVE_STRING_H
+# include <string.h>
+#endif
 
 int sockconnect_unix(const char *fname)
 {
