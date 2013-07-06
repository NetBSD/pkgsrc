$NetBSD: patch-asn.c,v 1.3 2013/07/06 09:57:20 tron Exp $

Fix build under Mac OS X (Lion).

--- asn.c.orig	2013-04-24 10:32:13.000000000 +0100
+++ asn.c	2013-07-06 10:55:12.000000000 +0100
@@ -21,9 +21,7 @@
 #include <stdlib.h>
 #include <sys/types.h>
 
-#ifndef __APPLE__
 #define BIND_8_COMPAT
-#endif
 #include <arpa/nameser.h>
 #ifdef HAVE_ARPA_NAMESER_COMPAT_H
 #include <arpa/nameser_compat.h>
