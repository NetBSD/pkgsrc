$NetBSD: patch-libvncserver_websockets.c,v 1.4 2018/01/02 10:09:06 jperkin Exp $

Byteswap compat for SunOS.

--- libvncserver/websockets.c.orig	2016-12-30 13:01:28.000000000 +0000
+++ libvncserver/websockets.c
@@ -44,6 +44,13 @@
 #include <sys/endian.h>
 #endif
 
+#if defined(__sun)
+#include <sys/byteorder.h>
+#define htobe64(x) BE_64(x)
+#define htobe32(x) BE_32(x)
+#define htobe16(x) BE_16(x)
+#endif
+
 #ifdef LIBVNCSERVER_HAVE_SYS_TYPES_H
 #include <sys/types.h>
 #endif
