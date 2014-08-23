$NetBSD: patch-utils_cups-browsed.c,v 1.3 2014/08/23 19:58:17 schnoebe Exp $

Move header below those providing u_int on NetBSD.
https://bugs.linuxfoundation.org/show_bug.cgi?id=1212

--- utils/cups-browsed.c.orig	2014-05-07 14:09:53.000000000 +0000
+++ utils/cups-browsed.c
@@ -23,15 +23,15 @@
 
 #include <ctype.h>
 #include <errno.h>
-#include <ifaddrs.h>
+#include <sys/types.h>
 #if defined(__OpenBSD__)
 #include <sys/socket.h>
 #endif /* __OpenBSD__ */
 #include <net/if.h>
 #include <netinet/in.h>
+#include <ifaddrs.h>
 #include <resolv.h>
 #include <stdio.h>
-#include <sys/types.h>
 #include <sys/stat.h>
 #include <assert.h>
 #include <stdlib.h>
