$NetBSD: patch-src_slproc.c,v 1.1 2018/05/17 10:35:59 jperkin Exp $

Set _XOPEN_SOURCE correctly on SunOS.

--- src/slproc.c.orig	2011-04-11 02:37:07.000000000 +0000
+++ src/slproc.c
@@ -20,12 +20,14 @@ Foundation, Inc., 59 Temple Place - Suit
 USA.
 */
 
+#if !defined(__sun) || (!defined(_XOPEN_SOURCE) && (__STDC_VERSION__-0 < 199901L))
 #ifndef _XOPEN_SOURCE
 # define _XOPEN_SOURCE
 #endif
 #ifndef _XOPEN_SOURCE_EXTENDED
 # define _XOPEN_SOURCE_EXTENDED 1
 #endif
+#endif
 
 #ifndef __EXTENSIONS__
 # define __EXTENSIONS__
