$NetBSD: patch-glib_tests_testing.c,v 1.1 2026/08/08 22:59:54 mef Exp $

revert the changes from 2.88.1 to 2.88.3
(with minor mod.)
to fix F_DUPFD_CLOEXEC undefined issue

--- /tmp/devel/glib2/work/glib-2.88.3/glib/tests/testing.c.orig	2026-07-29 22:17:36.000000000 +0900
+++ glib/tests/testing.c	2026-08-09 07:50:57.685554036 +0900
@@ -22,7 +22,6 @@
  * if advised of the possibility of such damage.
  */
 
-#define _POSIX_C_SOURCE 200809L  /* for F_DUPFD_CLOEXEC */
 
 #include "config.h"
 
@@ -37,6 +36,8 @@
 #include <stdlib.h>
 #include <string.h>
 
+#define _POSIX_C_SOURCE 200809L  /* for F_DUPFD_CLOEXEC */
+
 #ifdef G_OS_UNIX
 #include <fcntl.h>
 #include <glib-unix.h>
