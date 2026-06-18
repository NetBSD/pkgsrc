$NetBSD: patch-src_gdb.c,v 1.1 2026/06/18 15:50:48 nia Exp $

NetBSD and SunOS also need _NETBSD_SOURCE and __EXTENSIONS__
respectively to get strsep(3) defined when _POSIX_C_SOURCE
is 200112L.

--- src/gdb.c.orig	2026-06-18 15:47:36.854397453 +0000
+++ src/gdb.c
@@ -65,6 +65,8 @@
 // for addrinfo, struct timeval
 #define _POSIX_C_SOURCE 200112L
 // For strsep
+#define _NETBSD_SOURCE
+#define __EXTENSIONS__
 #define _DEFAULT_SOURCE
 #define _BSD_SOURCE
 #define _DARWIN_C_SOURCE
