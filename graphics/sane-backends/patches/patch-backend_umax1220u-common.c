$NetBSD: patch-backend_umax1220u-common.c,v 1.1 2025/12/19 12:07:47 nia Exp $

Fix implicit declaration of bcmp(3).

--- backend/umax1220u-common.c.orig	2025-12-19 11:50:08.955122239 +0000
+++ backend/umax1220u-common.c
@@ -57,6 +57,7 @@
 
 
 #include <string.h>
+#include <strings.h>
 #include <errno.h>
 #include <fcntl.h>
 #include <sys/types.h>
