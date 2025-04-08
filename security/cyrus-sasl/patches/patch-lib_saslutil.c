$NetBSD: patch-lib_saslutil.c,v 1.1 2025/04/08 00:57:13 maya Exp $

Don't guard the inclusion of time.h for two reasons:
1. It's a standard C header
2. There's no configure check for HAVE_TIME_H
(Shows up as a build failure on Fedora 41)

--- lib/saslutil.c.orig	2025-04-08 00:49:52.888164546 +0000
+++ lib/saslutil.c
@@ -59,9 +59,7 @@
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
 #endif
-#ifdef HAVE_TIME_H
 #include <time.h>
-#endif
 #include "saslint.h"
 #include <saslutil.h>
 
