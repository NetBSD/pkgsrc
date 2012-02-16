$NetBSD: patch-src_bytestream-socks5.c,v 1.1 2012/02/16 15:50:16 hans Exp $

--- src/bytestream-socks5.c.orig	2011-03-31 18:24:26.000000000 +0200
+++ src/bytestream-socks5.c	2012-01-24 19:56:40.685909024 +0100
@@ -42,6 +42,10 @@
  #include <ifaddrs.h>
 #endif
 
+#ifdef __sun
+#include <sys/sockio.h>
+#endif
+
 #include <dbus/dbus-glib.h>
 #include <dbus/dbus-glib-lowlevel.h>
 #include <telepathy-glib/interfaces.h>
