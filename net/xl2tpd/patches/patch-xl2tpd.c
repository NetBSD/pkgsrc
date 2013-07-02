$NetBSD: patch-xl2tpd.c,v 1.1 2013/07/02 00:22:17 christos Exp $

Expose functions, more headers

--- xl2tpd.c	2013-06-17 06:17:24.000000000 -0400
+++ xl2tpd.c	2013-06-11 19:51:00.000000000 -0400
@@ -19,6 +19,7 @@
 #define _BSD_SOURCE
 #define _XOPEN_SOURCE_EXTENDED
 #define _GNU_SOURCE
+#define _NETBSD_SOURCE
 
 #include <stdlib.h>
 #include <sys/types.h>
@@ -28,6 +29,7 @@
 #include <stdio.h>
 #include <stdarg.h>
 #include <errno.h>
+#include <signal.h>
 #include <unistd.h>
 #include <time.h>
 #if (__GLIBC__ < 2)
@@ -35,7 +37,7 @@
 #  include <sys/signal.h>
 # elif defined(LINUX)
 #  include <bsd/signal.h>
-# elif defined(SOLARIS)
+# elif defined(SOLARIS) || defined(NETBSD)
 #  include <signal.h>
 # endif
 #else
