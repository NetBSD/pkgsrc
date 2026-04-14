$NetBSD: patch-src_libsystemd_sd-bus_bus-gvariant.c,v 1.1 2026/04/14 10:58:10 kikadf Exp $

* NetBSD support

--- src/libsystemd/sd-bus/bus-gvariant.c.orig	2022-12-16 11:13:02.000000000 +0100
+++ src/libsystemd/sd-bus/bus-gvariant.c
@@ -2,6 +2,8 @@
 
 #ifdef __FreeBSD__
 #include <sys/endian.h>
+#elif defined(__NetBSD__)
+#include <endian.h>
 #endif
 
 #include <errno.h>
