$NetBSD: patch-plugins_mmexternal_mmexternal.c,v 1.2 2014/12/12 12:47:46 fhajny Exp $

Fix build on BSD.
--- plugins/mmexternal/mmexternal.c.orig	2014-11-25 15:45:35.000000000 +0000
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
