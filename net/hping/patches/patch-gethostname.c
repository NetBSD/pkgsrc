$NetBSD: patch-gethostname.c,v 1.1 2017/08/24 11:04:00 jperkin Exp $

strlcpy already exists on *BSD and Darwin

--- gethostname.c.orig	2002-03-28 15:54:48.000000000 +0000
+++ gethostname.c
@@ -16,7 +16,10 @@
 #include <arpa/inet.h>
 #include <string.h>
 
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && \
+    !defined(__bsdi__) && !defined(__APPLE__)
 size_t strlcpy(char *dst, const char *src, size_t siz);
+#endif
 
 char *get_hostname(char* addr)
 {
