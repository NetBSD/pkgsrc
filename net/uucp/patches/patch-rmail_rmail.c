$NetBSD: patch-rmail_rmail.c,v 1.1 2014/06/29 19:18:28 dholland Exp $

Fix build on platforms that don't have a NetBSD cdefs.h.

--- rmail/rmail.c~	2014-06-29 19:13:20.000000000 +0000
+++ rmail/rmail.c
@@ -31,6 +31,12 @@
 
 #include <sys/cdefs.h>
 #ifndef lint
+#ifndef __COPYRIGHT
+#define __COPYRIGHT(x) char rmail_copyright[] = x
+#endif
+#ifndef __RCSID
+#define __RCSID(x) char rmail_rcsid[] = x
+#endif
 __COPYRIGHT("@(#) Copyright (c) 1988, 1993\n\
 	The Regents of the University of California.  All rights reserved.\n");
 #if 0
