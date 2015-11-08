$NetBSD: patch-uucpd_uucpd.c,v 1.1 2015/11/08 22:06:52 dholland Exp $

Fix build on platforms that don't have a NetBSD cdefs.h.

--- uucpd/uucpd.c~	2015-11-08 21:56:30.000000000 +0000
+++ uucpd/uucpd.c
@@ -34,6 +34,12 @@
 
 #include <sys/cdefs.h>
 #ifndef lint
+#ifndef __COPYRIGHT
+#define __COPYRIGHT(x) char rmail_copyright[] = x
+#endif
+#ifndef __RCSID
+#define __RCSID(x) char rmail_rcsid[] = x
+#endif
 __COPYRIGHT("@(#) Copyright (c) 1985 The Regents of the University of California.\n\
  All rights reserved.\n");
 #if 0
