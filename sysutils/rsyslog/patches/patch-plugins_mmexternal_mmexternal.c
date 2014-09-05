$NetBSD: patch-plugins_mmexternal_mmexternal.c,v 1.1 2014/09/05 07:15:41 fhajny Exp $

Fix build on BSD.
--- plugins/mmexternal/mmexternal.c.orig	2014-08-18 09:14:06.000000000 +0000
+++ plugins/mmexternal/mmexternal.c
@@ -31,7 +31,7 @@
 #include <errno.h>
 #include <unistd.h>
 #include <fcntl.h>
-#include <wait.h>
+#include <sys/wait.h>
 #include <sys/uio.h>
 #include "conf.h"
 #include "syslogd-types.h"
