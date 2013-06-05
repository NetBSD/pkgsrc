$NetBSD: patch-support_time.c,v 1.1 2013/06/05 17:03:55 jperkin Exp $

Add necessary includes on SunOS.

--- support/time.c.orig	2013-04-25 09:01:57.000000000 +0000
+++ support/time.c
@@ -10,6 +10,9 @@
 #define _SVID_SOURCE
 #include <time.h>
 #include <errno.h>
+#ifdef __sun
+#include <unistd.h>
+#endif
 
 #include "map.h"
 #include "mph.h"
