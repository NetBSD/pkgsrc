$NetBSD: patch-misc.c,v 1.4 2022/07/15 21:21:29 wiz Exp $

* Fix sysctl build failure

--- misc.c.orig	2022-05-19 07:17:59.000000000 +0000
+++ misc.c
@@ -21,6 +21,9 @@
 #ifndef _MSC_VER
 #include <strings.h>
 #endif
+#if defined(__NetBSD__)
+#define _NETBSD_SOURCE
+#endif
 #include <stdlib.h>
 #include <math.h>
 #include "struct.h"
