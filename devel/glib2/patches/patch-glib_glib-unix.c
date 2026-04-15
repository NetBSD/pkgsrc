$NetBSD: patch-glib_glib-unix.c,v 1.1 2026/04/15 08:33:00 adam Exp $

Fix build on NetBSD.

--- glib/glib-unix.c.orig	2026-04-15 08:19:07.150066541 +0000
+++ glib/glib-unix.c
@@ -49,6 +49,7 @@
 #include <fcntl.h>
 #include <stdlib.h>   /* for fdwalk */
 #include <string.h>
+#include <sys/param.h> /* for MAXPATHLEN */
 #include <sys/types.h>
 #include <pwd.h>
 #include <unistd.h>
