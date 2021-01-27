$NetBSD: patch-erts_etc_unix_run__erl.c,v 1.1 2021/01/27 16:13:51 jperkin Exp $

Fix SunOS/C99.

--- erts/etc/unix/run_erl.c.orig	2018-12-10 20:11:00.000000000 +0000
+++ erts/etc/unix/run_erl.c
@@ -41,6 +41,9 @@
 #ifdef HAVE_CONFIG_H
 #  include "config.h"
 #endif
+#ifdef __sun
+#define __EXTENSIONS__
+#endif
 #ifdef HAVE_WORKING_POSIX_OPENPT
 #  ifndef _XOPEN_SOURCE
      /* On OS X, BSD and Solaris, we must leave _XOPEN_SOURCE undefined in order
