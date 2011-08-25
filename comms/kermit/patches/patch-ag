$NetBSD: patch-ag,v 1.2 2011/08/25 14:54:06 hans Exp $

--- ckuus6.c.orig	2011-06-07 17:27:51.000000000 +0200
+++ ckuus6.c	2011-08-23 10:34:29.697605882 +0200
@@ -33,11 +33,7 @@
 #endif /* def VMS [else] */
 #endif /* NOSTAT */
 
-#ifdef VMS
-#ifndef TCPSOCKET
 #include <errno.h>
-#endif /* TCPSOCKET */
-#endif /* VMS */
 
 #ifdef datageneral
 #define fgets(stringbuf,max,fd) dg_fgets(stringbuf,max,fd)
