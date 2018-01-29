$NetBSD: patch-erts_etc_unix_run__erl.c,v 1.1 2018/01/29 16:54:38 jperkin Exp $

Fix SunOS/C99.

--- erts/etc/unix/run_erl.c.orig	2017-12-11 20:10:59.000000000 +0000
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
      /* On OS X and BSD, we must leave _XOPEN_SOURCE undefined in order for
