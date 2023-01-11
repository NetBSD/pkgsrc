$NetBSD: patch-erts_etc_unix_run__erl.c,v 1.3 2023/01/11 21:58:43 nikita Exp $

Fix SunOS/C99.
Fix NetBSD.

--- erts/etc/unix/run_erl.c.orig	2022-12-12 08:30:54.000000000 +0100
+++ erts/etc/unix/run_erl.c	2023-01-11 22:30:49.938119650 +0100
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
@@ -81,7 +84,7 @@
 #ifdef HAVE_LIBUTIL_H
 #  include <libutil.h>
 #endif
-#ifdef HAVE_UTIL_H
+#if defined(HAVE_UTIL_H) || defined(__NetBSD__)
 #  include <util.h>
 #endif
 #ifdef HAVE_SYS_IOCTL_H
