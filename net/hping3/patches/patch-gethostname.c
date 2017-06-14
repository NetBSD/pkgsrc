$NetBSD: patch-gethostname.c,v 1.1 2017/06/14 12:17:30 jperkin Exp $

Delete conflicting strlcpy definition.

--- gethostname.c.orig	2003-09-01 00:22:06.000000000 +0000
+++ gethostname.c
@@ -18,8 +18,6 @@
 #include <arpa/inet.h>
 #include <string.h>
 
-size_t strlcpy(char *dst, const char *src, size_t siz);
-
 char *get_hostname(char* addr)
 {
 	static char answer[1024];
