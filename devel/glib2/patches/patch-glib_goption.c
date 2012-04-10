$NetBSD: patch-glib_goption.c,v 1.1 2012/04/10 19:48:17 bsiegert Exp $

This is needed on MirBSD, which does not have nitems
in sys/param.h, contrary to OpenBSD.
--- glib/goption.c.orig	Sun Mar 11 22:19:05 2012
+++ glib/goption.c
@@ -146,6 +146,10 @@
 #include <sys/sysctl.h>
 #endif
 
+#ifndef nitems
+#define nitems(_a)	(sizeof((_a)) / sizeof((_a)[0]))
+#endif
+
 #include "goption.h"
 
 #include "gprintf.h"
