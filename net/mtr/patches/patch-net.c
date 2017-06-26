$NetBSD: patch-net.c,v 1.3 2017/06/26 14:41:37 wiz Exp $

Fix build on SunOS.
--- net.c.orig	2013-04-29 18:22:05.000000000 +0000
+++ net.c
@@ -38,6 +38,9 @@
 #include <math.h>
 #include <errno.h>
 #include <string.h>
+#ifdef __sun
+#include <sys/filio.h>
+#endif
 
 #include "mtr.h"
 #include "net.h"
