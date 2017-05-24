$NetBSD: patch-dbus_dbus-sysdeps-unix.c,v 1.5 2017/05/24 08:06:28 jperkin Exp $

Support _XOPEN_SOURCE requirements on SunOS with different compiler defaults.

--- dbus/dbus-sysdeps-unix.c.orig	2017-02-16 13:46:23.000000000 +0000
+++ dbus/dbus-sysdeps-unix.c
@@ -24,6 +24,14 @@
 
 #include <config.h>
 
+#ifdef __sun
+#  if __STDC_VERSION__ - 0 < 199901L
+#define	_XOPEN_SOURCE	500
+#  else
+#define	_XOPEN_SOURCE	600
+#  endif
+#endif
+
 #include "dbus-internals.h"
 #include "dbus-sysdeps.h"
 #include "dbus-sysdeps-unix.h"
