$NetBSD: patch-libatalk_util_netatalk__conf.c,v 1.1 2023/03/02 10:39:57 jperkin Exp $

flock needs sys/file.h.

--- libatalk/util/netatalk_conf.c.orig	2023-01-10 09:49:35.000000000 +0000
+++ libatalk/util/netatalk_conf.c
@@ -24,6 +24,7 @@
 #include <utime.h>
 #include <errno.h>
 #include <string.h>
+#include <sys/file.h>
 #include <sys/param.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
