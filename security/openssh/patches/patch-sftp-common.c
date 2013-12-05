$NetBSD: patch-sftp-common.c,v 1.1.2.2 2013/12/05 09:52:53 tron Exp $

Include <unistd.h> for strmode(3).

--- sftp-common.c.orig	2013-06-01 21:31:19.000000000 +0000
+++ sftp-common.c
@@ -36,6 +36,9 @@
 #include <string.h>
 #include <time.h>
 #include <stdarg.h>
+#ifdef HAVE_UNISTD_H
+#include <unistd.h>
+#endif
 #ifdef HAVE_UTIL_H
 #include <util.h>
 #endif
