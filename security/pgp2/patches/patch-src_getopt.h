$NetBSD: patch-src_getopt.h,v 1.1 2025/10/10 19:11:59 mrg Exp $

Make sure the prototype for pgp_getopt() is present, even for UNIX builds.

--- getopt.h.orig	1995-08-09 00:34:07.000000000 -0700
+++ getopt.h	2025-10-10 12:05:20.586563908 -0700
@@ -1,4 +1,2 @@
-#ifndef UNIX	/* avoid conflict with stdlib.h */
 int pgp_getopt(int argc, char * const argv[], const char *opts);
-#endif
 
