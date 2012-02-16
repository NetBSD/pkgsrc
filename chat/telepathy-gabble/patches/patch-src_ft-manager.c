$NetBSD: patch-src_ft-manager.c,v 1.1 2012/02/16 15:50:16 hans Exp $

--- src/ft-manager.c.orig	2011-03-31 18:24:26.000000000 +0200
+++ src/ft-manager.c	2012-01-24 20:00:38.208583782 +0100
@@ -19,7 +19,9 @@
  */
 
 #define _BSD_SOURCE
+#ifndef __sun
 #define _XOPEN_SOURCE /* glibc2 needs this */
+#endif
 #include <time.h>
 #include <dbus/dbus-glib.h>
 #include <errno.h>
