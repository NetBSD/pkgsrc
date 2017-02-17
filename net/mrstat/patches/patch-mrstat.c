$NetBSD: patch-mrstat.c,v 1.1 2017/02/17 17:11:23 joerg Exp $

--- mrstat.c.orig	2017-02-17 11:57:14.884313822 +0000
+++ mrstat.c
@@ -13,6 +13,7 @@
 #include <sys/types.h>
 #include <sys/param.h>
 #include <sys/socket.h>
+#include <sys/stat.h>
 #include <err.h>
 #include <fcntl.h>
 #include <netdb.h>
