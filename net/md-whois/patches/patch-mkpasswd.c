$NetBSD: patch-mkpasswd.c,v 1.1 2017/02/17 17:10:37 joerg Exp $

--- mkpasswd.c.orig	2017-02-17 12:01:45.221231875 +0000
+++ mkpasswd.c
@@ -30,6 +30,7 @@
 #endif
 #include <fcntl.h>
 #include <string.h>
+#include <strings.h>
 #include <time.h>
 #include <sys/types.h>
 #ifdef HAVE_XCRYPT
