$NetBSD: patch-src_zzuf.c,v 1.1 2017/04/16 21:46:12 khorben Exp $

Build fix for NetBSD, where:
* <alloca.h> does not exist but alloca(3) is available in <stdlib.h> instead
* <sys/select.h> is not automatically visible

--- src/zzuf.c.orig	2016-04-13 08:24:10.000000000 +0000
+++ src/zzuf.c
@@ -48,7 +48,12 @@
 #include <errno.h>
 #include <signal.h>
 #include <libgen.h>
-#include <alloca.h>
+#if defined HAVE_ALLOCA_H
+#   include <alloca.h>
+#endif
+#if defined HAVE_SYS_SELECT_H
+#   include <sys/select.h>
+#endif
 #if defined HAVE_SYS_TIME_H
 #   include <sys/time.h>
 #endif
