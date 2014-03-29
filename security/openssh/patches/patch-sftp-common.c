$NetBSD: patch-sftp-common.c,v 1.2 2014/03/29 09:38:11 taca Exp $

Include <unistd.h> for strmode(3).

--- sftp-common.c.orig	2014-01-09 23:40:45.000000000 +0000
+++ sftp-common.c
@@ -37,6 +37,9 @@
 #include <string.h>
 #include <time.h>
 #include <stdarg.h>
+#ifdef HAVE_UNISTD_H
+#include <unistd.h>
+#endif
 #ifdef HAVE_UTIL_H
 #include <util.h>
 #endif
