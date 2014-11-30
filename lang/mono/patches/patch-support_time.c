$NetBSD: patch-support_time.c,v 1.2 2014/11/30 08:40:51 spz Exp $

Add necessary includes on SunOS.

--- support/time.c.orig	2014-09-22 13:23:09.000000000 +0000
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
