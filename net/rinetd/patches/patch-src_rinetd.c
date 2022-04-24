$NetBSD: patch-src_rinetd.c,v 1.1 2022/04/24 01:35:39 tnn Exp $

include <netdb.h> for NI_MAXHOST

--- src/rinetd.c.orig	2021-02-19 08:57:10.000000000 +0000
+++ src/rinetd.c
@@ -37,6 +37,7 @@
 #include <signal.h>
 #include <stdlib.h>
 #include <fcntl.h>
+#include <netdb.h>
 #if _WIN32 || (!TIME_WITH_SYS_TIME && !HAVE_SYS_TIME_H)
 #	include <time.h>
 #endif
