$NetBSD: patch-xl2tpd.c,v 1.2 2014/02/14 22:06:39 christos Exp $

Expose functions

--- xl2tpd.c.orig	2014-01-16 17:02:04.000000000 -0500
+++ xl2tpd.c	2014-02-14 14:27:24.000000000 -0500
@@ -19,6 +19,7 @@
 #define _BSD_SOURCE
 #define _XOPEN_SOURCE_EXTENDED
 #define _GNU_SOURCE
+#define _NETBSD_SOURCE
 
 #include <stdlib.h>
 #include <sys/types.h>
