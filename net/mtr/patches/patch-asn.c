$NetBSD: patch-asn.c,v 1.7 2017/06/26 14:41:37 wiz Exp $

Fix build on Darwin.

--- asn.c.orig	2017-02-17 02:50:57.000000000 +0000
+++ asn.c
@@ -23,9 +23,6 @@
 #include <stdlib.h>
 #include <sys/types.h>
 
-#ifdef __APPLE__
-#define BIND_8_COMPAT
-#endif
 #include <arpa/nameser.h>
 #ifdef HAVE_ARPA_NAMESER_COMPAT_H
 #include <arpa/nameser_compat.h>
