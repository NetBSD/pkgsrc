$NetBSD: patch-xl2tpd.c,v 1.3 2017/10/13 17:24:05 christos Exp $

Expose functions

--- xl2tpd.c.orig	2017-08-02 13:46:06.000000000 -0400
+++ xl2tpd.c	2017-10-13 12:50:10.384619299 -0400
@@ -20,6 +20,7 @@
 #define _DEFAULT_SOURCE
 #define _XOPEN_SOURCE_EXTENDED	1
 #define _GNU_SOURCE
+#define _NETBSD_SOURCE
 
 #include <stdlib.h>
 #include <sys/types.h>
