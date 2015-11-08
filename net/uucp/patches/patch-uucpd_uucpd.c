$NetBSD: patch-uucpd_uucpd.c,v 1.2 2015/11/08 23:19:22 dholland Exp $

Fix build on platforms that don't have a NetBSD cdefs.h.

--- uucpd/uucpd.c~	2015-11-08 21:56:30.000000000 +0000
+++ uucpd/uucpd.c
@@ -34,6 +34,12 @@
 
 #include <sys/cdefs.h>
 #ifndef lint
+#ifndef __COPYRIGHT
+#define __COPYRIGHT(x) char uucpd_copyright[] = x
+#endif
+#ifndef __RCSID
+#define __RCSID(x) char uucpd_rcsid[] = x
+#endif
 __COPYRIGHT("@(#) Copyright (c) 1985 The Regents of the University of California.\n\
  All rights reserved.\n");
 #if 0
