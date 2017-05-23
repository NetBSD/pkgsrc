$NetBSD: patch-dbus_dbus-sysdeps-unix.c,v 1.4 2017/05/23 15:12:57 jperkin Exp $

Support _XOPEN_SOURCE requirements on SunOS with different compiler defaults.

--- dbus/dbus-sysdeps-unix.c.orig	2017-02-16 13:46:23.000000000 +0000
+++ dbus/dbus-sysdeps-unix.c
@@ -24,6 +24,12 @@
 
 #include <config.h>
 
+#if defined(__sun) && __STDC_VERSION__ - 0 < 199901L
+#define	_XOPEN_SOURCE	500
+#else
+#define	_XOPEN_SOURCE	600
+#endif
+
 #include "dbus-internals.h"
 #include "dbus-sysdeps.h"
 #include "dbus-sysdeps-unix.h"
